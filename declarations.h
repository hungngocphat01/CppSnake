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
extern bool GAMEOVER;
extern char bodyc[2], headc[2], borderc[2], foodc[2];
extern int delaytime;

#define MINW 70
#define MINH 20