#pragma once
#include "declarations.h"
#include "canvas.h"

#define TEXTURE_MAX_HEIGHT 12
#define TEXTURE_MAX_WIDTH 70

int CANVAS_H, CANVAS_W;
bool SHOWDEBUG = false;

void drawFrame() {
    // Draw vertical bars
    for (unsigned i = cvTY(); i <= cvBY(); i++) {
        mvprintw(i, cvLX(), BORDERC);
        mvprintw(i, cvRX(), BORDERC);
    }

    // Draw horizontal bars
    for (unsigned i = cvLX(); i <= cvRX(); i++) {
        mvprintw(cvTY(), i, BORDERC);
        mvprintw(cvBY(), i, BORDERC);
    }
}

inline void guiInit() {
    initscr();
	noecho();
	curs_set(FALSE);
    getmaxyx(stdscr, SCR_HEIGHT, SCR_WIDTH);

    // Default value
    CANVAS_H = SCR_HEIGHT - 1;
    CANVAS_W = SCR_WIDTH - 1;

    // Disable getch() wait
    cbreak();
	nodelay(stdscr, TRUE);	
}

inline void showDebugInfo() {
    if (SHOWDEBUG) {
        mvprintw(0, 0, argp_program_version);
        mvprintw(1, 0, "Screen size: %dx%d", SCR_WIDTH, SCR_HEIGHT);
        mvprintw(2, 0, "Canvas size: %dx%d", CANVAS_W, CANVAS_H);
        refresh();
    }
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
    showDebugInfo();
    pauseProg();
}

inline void gameOver() {
    clear();
    printFromFile("./texture/gameover.dat");
    showDebugInfo();
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

inline void pauseGame() {
    clear();
    printFromFile("./texture/pause.dat");
    showDebugInfo();
    pauseProg();
}