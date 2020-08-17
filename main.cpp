#include "declarations.h"
#include "snake.h"
#include "gui.h"

int SHEIGHT, SWIDTH;
bool GAMEOVER = false;

int main () {
	// Initialize
	guiInit();
	checkTermSize();
	srand(time(NULL));

	printMenu();

	int keyread;

	snake s;
	s.head = {SWIDTH/2, SHEIGHT/2};
	s.genfood();
	s.drawfood();
	refresh();
	
	const char* guidestr = "Press P to pause, Q to quit.";
	clear();
	mvprintw(SHEIGHT/2 - 1, SWIDTH/2 - strlen(guidestr)/2 + 1, guidestr);
	refresh();
	napms(1000);

	while (1) {
		checkTermSize();
		getmaxyx(stdscr, SHEIGHT, SWIDTH);
		keyread = getch();

		// Easter egg
		if (keyread == '/') {
			s.grow();
		}
		else if (keyread == 'q' || GAMEOVER) {
			break;
		}
		else if (keyread == 'p') {
			pauseGame();
		}

		clear();
		drawFrame();
		s.move(keyread);
		s.drawfood();
		s.drawsnake();
		
		// mvprintw(SHEIGHT - 1, 0, "px=%d py=%d", s.prey.x, s.prey.y);
		// mvprintw(SHEIGHT - 2, 0, "x=%d y=%d", s.head.x, s.head.y);
		// mvprintw(my - 3, 0, "getch=%c", direction);
		// mvprintw(my - 4, 0, "len=%d", s.len);
		refresh();
		napms(200);
	}	
	gameOver();
	endwin();
	return 0;
}