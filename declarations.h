#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <exception>

#ifdef __APPLE__
    // Must "brew install argp-standalone" first
    #include "/usr/local/include/argp.h"
#else
    #include <argp.h>
#endif

extern int32_t SCR_HEIGHT, SCR_WIDTH;
extern int32_t CANVAS_H, CANVAS_W;
extern bool GAMEOVER;
extern bool DEBUGMODE;
extern char BODYC[2], HEADC[2], BORDERC[2], FOODC[2];
extern int32_t DELAYTIME;
extern const char* argp_program_version;
extern int32_t SCORE;
extern char LOADFILENAME[255];

#define MINW 70
#define MINH 20