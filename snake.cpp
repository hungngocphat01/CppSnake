#include "snake.h"
#include "declarations.h"

int randomInt(int start, int end) {
    return rand() % (end - start + 1) + start;
}

void snake::drawsnake() {
    mvprintw(this->head.y, this->head.x, "O");
    for (unsigned i = 1; i < this->len; i++) {
        mvprintw(this->body[i].y, this->body[i].x, "X");
    }
}

void snake::genfood() {
    do {
        this->prey.x = randomInt(2, SWIDTH - 2);
        this->prey.y = randomInt(2, SHEIGHT - 2);
    } while (this->overlaps(this->prey));
}

void snake::drawfood() {
    mvprintw(this->prey.y, this->prey.x, ".");
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
    if (this->head.x == this->prey.x && this->head.y == this->prey.y) {
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
    if (this->head.x >= SWIDTH - 1 || this->head.x < 1 || this->head.y >= SHEIGHT - 1 || this->head.y < 1) {
        GAMEOVER = true;
    }
}