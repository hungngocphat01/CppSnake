#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#ifdef __APPLE__
    // Must "brew install argp-standalone" first
    #include "/usr/local/include/argp.h"
#else
    #include <argp.h>
#endif

extern int SCR_HEIGHT, SCR_WIDTH;
extern int CANVAS_H, CANVAS_W;
extern bool GAMEOVER;
extern bool SHOWDEBUG;
extern char BODYC[2], HEADC[2], BORDERC[2], FOODC[2];
extern int DELAYTIME;
extern const char* argp_program_version;
extern unsigned SCORE;

#define MINW 70
#define MINH 20