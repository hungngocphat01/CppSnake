#include "declarations.h"
#define TEXTURE_MAX_HEIGHT 12
#define TEXTURE_MAX_WIDTH 70

void pauseProg() {
    nodelay(stdscr, FALSE);	
    char c;
    do
    {
        c = getch();
    } while (c != ' ');
    nodelay(stdscr, TRUE);
}

void drawFrame() {
    // Draw vertical bars
    for (unsigned i = 0; i < SCR_HEIGHT; i++) {
        mvprintw(i, 0, borderc);
        mvprintw(i, SCR_WIDTH - 1, borderc);
    }

    // Draw horizontal bars
    for (unsigned i = 0; i < SCR_WIDTH; i++) {
        mvprintw(0, i, borderc);
        mvprintw(SCR_HEIGHT - 1, i, borderc);
    }
}

inline void guiInit() {
    initscr();
	noecho();
	curs_set(FALSE);
    getmaxyx(stdscr, SCR_HEIGHT, SCR_WIDTH);	

    // Disable getch() wait
    cbreak();
	nodelay(stdscr, TRUE);	
}

void printFromFile(const char* filename) {
    FILE* fp = fopen(filename, "rt");
    if (fp == nullptr) {
        mvprintw(0, 0, "File not found: %s", filename);
        pauseProg();
        endwin();
        exit(-1);
    }

    char lbuffer[TEXTURE_MAX_HEIGHT][TEXTURE_MAX_WIDTH];
    unsigned lines = -1;
    unsigned max_width = 0;

    // Count lines and max_width
    while (!feof(fp)) {
        lines++;
        fgets(lbuffer[lines], 70, fp);
        unsigned llen = strlen(lbuffer[lines]);
        if (llen > max_width) {
            max_width = llen;
        }
        if (lines >= TEXTURE_MAX_HEIGHT) {
            lines = TEXTURE_MAX_HEIGHT;
            break;
        }
    }

    unsigned x = SCR_WIDTH/2 - max_width/2;
    unsigned y = SCR_HEIGHT/2 - lines/2;

    for (unsigned i = 0; i <= lines; i++) {
        mvprintw(y++, x, lbuffer[i]);
    }
    refresh();
    fclose(fp);
}

inline void printMenu() {
    clear();
    printFromFile("./texture/title.dat");
    pauseProg();
}

inline void pauseGame() {
    clear();
    printFromFile("./texture/pause.dat");
    pauseProg();
}

inline void gameOver() {
    clear();
    printFromFile("./texture/gameover.dat");
    pauseProg();
}

void checkTermSize() {
    while (SCR_WIDTH < MINW || SCR_HEIGHT < MINH) {
        clear();
		mvprintw(0, 0, "Your terminal size is insufficent to play the game.\nResize it to at least %dx%d (WxH) and press SPACE to continue.\nCurrent size: %dx%d", MINW, MINH, SCR_WIDTH, SCR_HEIGHT);
        refresh();
        pauseProg();
        getmaxyx(stdscr, SCR_HEIGHT, SCR_WIDTH);	
	}
}