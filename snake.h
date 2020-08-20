#include <vector>

struct point {
	int x = 0;
	int y = 0;
};

#define DEFAULT_HEAD "@"
#define DEFAULT_BODY "O"
#define DEFAULT_FOOD "X"

struct snake {
	unsigned len = 1; // Length of the snake
	unsigned alloc_len = 10;
	point* body = (point*)malloc(alloc_len * sizeof(point));
	point food = {-1, -1}; // Current food
	int dx = 1; // x axis increment
	int dy = 0; // y axis increment

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