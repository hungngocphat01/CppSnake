csnake: main.cpp snake.cpp
	g++ $^ -o $@ -lncurses -std=c++17
