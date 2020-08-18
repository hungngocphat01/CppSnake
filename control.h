#include "declarations.h"

static inline void pauseProg() {
    nodelay(stdscr, FALSE);	
    char c;
    do
    {
        c = getch();
    } while (c != ' ');
    nodelay(stdscr, TRUE);
}