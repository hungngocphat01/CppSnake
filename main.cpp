#include "declarations.h"
#include "snake.h"
#include "gui.h"
#include "arguments.h"

int32_t SCR_HEIGHT, SCR_WIDTH;
bool GAMEOVER = false;
int32_t DELAYTIME = 200;
char LOADFILENAME[255];

int main (int argc, char** argv) {
	// Initialize GUI
	if (!ifHelp(argc, argv)) 
		guiInit();
	argp_parse(&Argp, argc, argv, 0, 0, 0);
	checkTermSize();
	checkCanvas();
	srand(time(NULL));
	snake s;

	try {
		printMenu();

		int keyread;

		if (strlen(LOADFILENAME) != 0) {
			if(!s.read(LOADFILENAME)){
				endwin();
				return -1;
			}
			else {
				SCORE = (s.len - 1) * 10;
			}
		}
		else {
			s.head = {SCR_WIDTH/2, SCR_HEIGHT/2};
			s.head = {SCR_WIDTH/2, SCR_HEIGHT/2};
			s.genfood();
		}
		s.drawfood();
		refresh();
		
		const char* guidestr = "Press P to pause, Q to quit, O to save.";
		clear();
		mvprintw(SCR_HEIGHT/2 - 1, SCR_WIDTH/2 - strlen(guidestr)/2 + 1, guidestr);
		refresh();
		napms(2000);

		while (1) {
			checkTermSize();
			checkCanvas();
			getmaxyx(stdscr, SCR_HEIGHT, SCR_WIDTH);
			keyread = getch();

			// Easter egg
			if (keyread == '/') {
				if (DEBUGMODE)
					s.grow();
			}
			else if (keyread == 'q' || GAMEOVER) {
				break;
			}
			else if (keyread == 'p') {
				pauseGame();
			}
			else if (keyread == 'o') {
				showSavePrompt(s);
			}

			clear();
			drawFrame();
			s.move(keyread);
			s.drawfood();
			s.drawsnake();
			
			// mvprintw(SCR_HEIGHT - 2, 0, "x=%d y=%d", s.head.x, s.head.y);
			// mvprintw(my - 3, 0, "getch=%c", direction);
			// mvprintw(my - 4, 0, "len=%d", s.len);
			refresh();
			napms(DELAYTIME);
		}	
	}
	catch (const std::exception& e) {
		mvprintw(0, 0, "An error occurred: %s", e.what());
		pauseProg();
	}

	free(s.body);
	gameOver();
	endwin();
	return 0;
}