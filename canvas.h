#pragma once
#include "declarations.h"
#include "control.h"

// Canvas Left X
inline int cvLX() {
    return (SCR_WIDTH - 1 - CANVAS_W)/2;
}
// Canvas Right X
inline int cvRX() {
    return cvLX() + CANVAS_W;
}
// Canvas Top Y
inline int cvTY() {
    return (SCR_HEIGHT - 1 - CANVAS_H)/2;
}
// Canvas Bottom Y
inline int cvBY() {
    return cvTY() + CANVAS_H;
}

inline bool divisible(int a, int b) {
    return (a % b == 0);
}

static void checkCanvas() {
    if (CANVAS_W >= SCR_WIDTH || CANVAS_H >= SCR_HEIGHT || CANVAS_H < 10 || CANVAS_W < 10) {
        mvprintw(0, 0, "Canvas size is out of range or insufficient.\n\nMin canvas size: 10x10\nCanvas size: %dx%x\nTerminal size: %dx%d", CANVAS_W, CANVAS_H, SCR_WIDTH, SCR_HEIGHT);
        pauseProg();
        endwin();
        exit(-1);
    }
    if (!divisible(SCR_WIDTH - 1 - CANVAS_W, 2)) {
        if (divisible(SCR_WIDTH - 1 - (CANVAS_W + 1), 2))
            CANVAS_W++;
        else
            CANVAS_W--;
    }
    if (!divisible(SCR_HEIGHT - 1 - CANVAS_H, 2)) {
        if (divisible(SCR_HEIGHT - 1 - (CANVAS_H + 1), 2))
            CANVAS_H++;
        else 
            CANVAS_H--;
    }
}