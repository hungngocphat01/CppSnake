#pragma once
#include "declarations.h"
#include "canvas.h"

#define TEXTURE_MAX_HEIGHT 12
#define TEXTURE_MAX_WIDTH 70

int32_t CANVAS_H, CANVAS_W;
bool DEBUGMODE = false;

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

    // Print score
    char scorestr[20];
    sprintf(scorestr, "SCORE: %d", SCORE);
    unsigned scorestr_x = (SCR_WIDTH)/2 - strlen(scorestr)/2;
    mvprintw(cvTY(), scorestr_x, scorestr);
    mvprintw(cvTY(), scorestr_x - 1, " ");
    mvprintw(cvTY(), scorestr_x + strlen(scorestr), " ");
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
    if (DEBUGMODE) {
        mvprintw(0, 0, argp_program_version);
        mvprintw(1, 0, "Screen size: %dx%d", SCR_WIDTH, SCR_HEIGHT);
        mvprintw(2, 0, "Canvas size: %dx%d", CANVAS_W, CANVAS_H);
        if (strlen(LOADFILENAME) != 0) {
            mvprintw(3, 0, "Game loaded from: %s", LOADFILENAME);
        }
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

void notify(char* content) {
    clear();
    mvprintw(0, 0, content);
    refresh();
    pauseProg();
}

inline bool isValidChar(char c) {
    return (c >= 32 && c <= 126 && c != '/' && c != ':');
}

void showSavePrompt(snake s) {
    clear();
    mvprintw(0, 0, "Enter savefile name: ");
    refresh();

    curs_set(TRUE);
    nocbreak();
    nodelay(stdscr, FALSE);	
    echo();
    
    char filename[255];
    getstr(filename);
    curs_set(FALSE);
    cbreak();
    noecho();

    clear();
    if (s.write(filename)) {
        mvprintw(0, 0, "Saved successfully to \"%s\". Press SPACE to resume.", filename);
    }
    else {
        mvprintw(0, 0, "Save failed.\nPress SPACE to resume");
    }
    refresh();
    pauseProg();
    
}