#include <stdlib.h>

struct point {
	int32_t x = 0;
	int32_t y = 0;
};

class snake {
public:
	int32_t len = 1; // Length of the snake
	int32_t alloc_len = 10;
	point* body = (point*)malloc(this->alloc_len * sizeof(point));;
	point food = {-1, -1}; // Current food
	int32_t dx = 1; // x axis increment
	int32_t dy = 0; // y axis increment

	// Reference to the snake's head
	point& head = body[0];

	void drawsnake(); // Draw the snake
	void genfood(); // Generate new food
	void drawfood(); // Draw food
	void grow(); // Grow the snake
	void move(char direction); // Move the snake
	bool overlaps(point a); // Check if a given point overlaps the snake
	bool write(char* filename);
	bool read(char* filename);
};