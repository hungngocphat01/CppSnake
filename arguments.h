#include "declarations.h"

const char* argp_program_version = "CppSnake 2.0";
const char* doc = "A simple Snake game written in C++";

argp_option options[] = {
    {"body", 'b', "BODYC", 0, "Set body character"},
    {"head", 'h', "HEADC", 0, "Set head character"},
    {"border", 'd', "BORDERC", 0, "Set border character"},
    {"food", 'f', "FOODC", 0, "Set food character"},
    {"interval", 'i', "INVERVAL", 0, "Set the snake's speed (nanosecond)"},
    { 0 }
};

static error_t parse_opt(int key, char* arg, argp_state* state) {
    switch (key) {
    case 'b':
        memcpy(bodyc, arg, 1);
        bodyc[1] = '\0';
        break;
    case 'h':
        memcpy(headc, arg, 1);
        headc[1] = '\0';
        break;
    case 'd':
        memcpy(borderc, arg, 1);
        borderc[1] = '\0';
        break;
    case 'f':
        memcpy(foodc, arg, 1);
        foodc[1] = '\0';
        break;
    case 'i':
        delaytime = atoi(arg);
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static argp Argp = {options, (argp_parser_t)parse_opt, 0, doc};

