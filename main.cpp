#include "declarations.h"
#include "snake.h"
#include "gui.h"
#include "arguments.h"

int SCR_HEIGHT, SCR_WIDTH;
bool GAMEOVER = false;
int delaytime = 300;

int main (int argc, char** argv) {
	argp_parse(&Argp, argc, argv, 0, 0, 0);

	// Initialize GUI
	guiInit();
	checkTermSize();
	srand(time(NULL));

	printMenu();

	int keyread;

	snake s;
	s.head = {SCR_WIDTH/2, SCR_HEIGHT/2};
	s.genfood();
	s.drawfood();
	refresh();
	
	const char* guidestr = "Press P to pause, Q to quit.";
	clear();
	mvprintw(SCR_HEIGHT/2 - 1, SCR_WIDTH/2 - strlen(guidestr)/2 + 1, guidestr);
	refresh();
	napms(1000);

	while (1) {
		checkTermSize();
		getmaxyx(stdscr, SCR_HEIGHT, SCR_WIDTH);
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
		
		// mvprintw(SCR_HEIGHT - 1, 0, "px=%d py=%d", s.prey.x, s.prey.y);
		// mvprintw(SCR_HEIGHT - 2, 0, "x=%d y=%d", s.head.x, s.head.y);
		// mvprintw(my - 3, 0, "getch=%c", direction);
		// mvprintw(my - 4, 0, "len=%d", s.len);
		refresh();
		napms(delaytime);
	}	
	gameOver();
	endwin();
	return 0;
}