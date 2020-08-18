#include "snake.h"
#include "declarations.h"
#include "canvas.h"

char BODYC[2] = "O", HEADC[2] = "@", FOODC[2] = "X";
char BORDERC[2] = "#";
unsigned SCORE = 0;

int randomInt(int start, int end) {
    return rand() % (end - start + 1) + start;
}

void snake::drawsnake() {
    mvprintw(this->head.y, this->head.x, HEADC);
    for (unsigned i = 1; i < this->len; i++) {
        mvprintw(this->body[i].y, this->body[i].x, BODYC);
    }
}

void snake::genfood() {
    do {
        this->food.x = randomInt(cvLX() + 1, cvRX() - 1);
        this->food.y = randomInt(cvTY() + 1, cvBY() - 1);
    } while (this->overlaps(this->food));
}

void snake::drawfood() {
    mvprintw(this->food.y, this->food.x, FOODC);
}

void snake::grow() {
    this->len++;
}

bool snake::overlaps(point a) {
    for (unsigned i = 1; i < this->len; i++) {
        if (a.x == this->body[i].x && a.y == this->body[i].y) {
            return true;
        }
    }
    return false;
}

void snake::move(char direction) {
    if (this->head.x == this->food.x && this->head.y == this->food.y) {
        this->grow();
        this->genfood();
    }
    switch (direction) {
        case 'a':
            this->dx = -1;
            this->dy = 0;
            break;
        case 'd':
            this->dx = 1;
            this->dy = 0;
            break;
        case 's':
            this->dx = 0;
            this->dy = 1;
            break;
        case 'w':
            this->dx = 0;
            this->dy = -1;
            break;
    }
    for (unsigned i = this->len - 1; i >= 1; i--) {
        this->body[i].x = this->body[i - 1].x;
        this->body[i].y = this->body[i - 1].y;
    }
    this->head.x += this->dx;
    this->head.y += this->dy;

    // Check if snake slams into itself
    if (this->overlaps(this->head)) {
        GAMEOVER = true;
    }
    // Check if the snake go out of bounds
    if (this->head.x >= cvRX() || this->head.x <= cvLX() || this->head.y >= cvBY() || this->head.y < cvTY()) {
        GAMEOVER = true;
    }
}