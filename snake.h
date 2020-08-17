struct point {
	int x = 0;
	int y = 0;
};

struct snake {
	unsigned len = 1; // Length of the snake
	point body[50]; // Coordinates of the snake's body blocks. snake head = 0
	point prey = {-1, -1}; // Current prey
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
};