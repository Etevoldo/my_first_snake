#include <stdlib.h>
#include <time.h>
#include "fruit.h"
#include "engine.h"

struct fruit fruit_initialize(int snake_x_pos, int snake_y_pos){
    srand((unsigned) time(NULL));
    struct fruit fruit;
    fruit.x_pos = rand() % CANVAS_WIDTH;
    fruit.y_pos = rand() % CANVAS_HEIGHT;
    //todo: add a conditional to not spawn on the body
    return fruit;
}

void fruit_respawn(struct fruit *fruit, int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT]){
    int spawn_col = 1;
    srand((unsigned) time(NULL));
    while (spawn_col == 1){
        fruit->x_pos = rand() % CANVAS_WIDTH;
        fruit->y_pos = rand() % CANVAS_HEIGHT;
        if (canvas_ocupy[fruit->x_pos][fruit->y_pos] > 0){
            spawn_col = 1;
        }
        else 
            spawn_col = 0;
    }
}

void fruit_render(struct fruit *fruit, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
    canvas[fruit->x_pos][fruit->y_pos] = -1;
}