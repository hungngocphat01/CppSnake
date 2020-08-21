#include "snake.h"
#include "declarations.h"
#include "canvas.h"

char BODYC[2] = "O", HEADC[2] = "@", FOODC[2] = "X";
char BORDERC[2] = "#";
int32_t SCORE = 0;

int32_t randomInt(int start, int end) {
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
    if (this->len >= this->alloc_len - 1) {
        this->alloc_len += 10;
        this->body = (point*)realloc(this->body, this->alloc_len * sizeof(point));
    }
    SCORE = (this->len - 1)*10;
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

bool snake::write(char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        clear();
        mvprintw(0, 0, "A file cannot be created!!!\nPress SPACE to resume.");
        refresh();
        pauseProg();
        return false;
    }
    // Validate signal
    fwrite("MIKIMIKI", 8, 1, fp);
    fwrite(&CANVAS_W, sizeof(CANVAS_W), 1, fp);
    fwrite(&CANVAS_H, sizeof(CANVAS_W), 1, fp);
    fwrite(&len, sizeof(len), 1, fp);
    fwrite(&alloc_len, sizeof(alloc_len), 1, fp);
    fwrite(body, sizeof(point), alloc_len, fp);
    fwrite(&head, sizeof(head), 1, fp);
    fwrite(&food, sizeof(food), 1, fp);
    fwrite(&dx, sizeof(dx), 1, fp);
    fwrite(&dy, sizeof(dy), 1, fp);
    fclose(fp);
    return true;
}

bool snake::read(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        clear();
        mvprintw(0, 0, "File \"%s\" can't be opened.\nEither corrupted or not exist.\nPress SPACE to exit.", filename);
        refresh();
        pauseProg();
        return false;
    }

    char mikimiki[8];
    fread(mikimiki, 8, 1, fp);
    if (!!memcmp(mikimiki, "MIKIMIKI", 8)) {
        clear();
        mvprintw(0, 0, "File \"%s\" is corrupted.\nPress SPACE to exit.", filename);
        refresh();
        pauseProg();
        fclose(fp);
        return false;
    }
    fread(&CANVAS_W, sizeof(CANVAS_W), 1, fp);
    fread(&CANVAS_H, sizeof(CANVAS_W), 1, fp);
    fread(&len, sizeof(len), 1, fp);
    fread(&alloc_len, sizeof(alloc_len), 1, fp);
    body = (point*)realloc(body, alloc_len * sizeof(point));
    fread(body, sizeof(point), alloc_len, fp);
    fread(&head, sizeof(head), 1, fp);
    fread(&food, sizeof(food), 1, fp);
    fread(&dx, sizeof(dx), 1, fp);
    fread(&dy, sizeof(dy), 1, fp);
    fclose(fp);
    return true;
}