snake: main.cpp snake.cpp
	g++ $^ -o $@ -lncurses -largp -std=c++17 -g
