#pragma once
#include "declarations.h"

const char* argp_program_version = "CppSnake 3.0";
const char* doc = "A simple Snake game written in C++";

argp_option options[] = {
    {"body", 'b', "BODYC", 0, "Set body character."},
    {"head", 'h', "HEADC", 0, "Set head character."},
    {"border", 'B', "BORDERC", 0, "Set border character."},
    {"food", 'f', "FOODC", 0, "Set food character."},
    {"interval", 'i', "INVERVAL", 0, "Set the snake's speed (nanosecond)."},
    {"width", 'W', "XSIZE", 0, "Set canvas width."},
    {"height", 'H', "YSIZE", 0, "Set canvas height."},
    {"debug", 'D', 0, 0, "Show debug information."},
    { 0 }
};

static error_t parse_opt(int key, char* arg, argp_state* state) {
    switch (key) {
    case 'b':
        memcpy(BODYC, arg, 1);
        BODYC[1] = '\0';
        break;
    case 'h':
        memcpy(HEADC, arg, 1);
        HEADC[1] = '\0';
        break;
    case 'B':
        memcpy(BORDERC, arg, 1);
        BORDERC[1] = '\0';
        break;
    case 'f':
        memcpy(FOODC, arg, 1);
        FOODC[1] = '\0';
        break;
    case 'i':
        DELAYTIME = atoi(arg);
        break;
    case 'W':
        CANVAS_W = atoi(arg);
        break;
    case 'H':
        CANVAS_H = atoi(arg);
        break;
    case 'D':
        SHOWDEBUG = true;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static argp Argp = {options, (argp_parser_t)parse_opt, 0, doc};

