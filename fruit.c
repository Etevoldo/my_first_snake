#include <stdlib.h>
#include <time.h>
#include "fruit.h"
#include "engine.h"

struct fruit fruit_initialize(Snake snake){
    int spawn_col = 1;
    srand((unsigned) time(NULL));
    struct fruit fruit;
    while (spawn_col == 1){
        fruit.x_pos = rand() % CANVAS_WIDTH;
        fruit.y_pos = rand() % CANVAS_HEIGHT;
        if (snake_is_ocupy(snake, fruit.x_pos, fruit.y_pos)){
            spawn_col = 1;
        }
        else 
            spawn_col = 0;
    }
    return fruit;
}

void fruit_respawn(struct fruit *fruit, Snake snake){
    int spawn_col = 1;
    srand((unsigned) time(NULL));
    while (spawn_col == 1){
        fruit->x_pos = rand() % CANVAS_WIDTH;
        fruit->y_pos = rand() % CANVAS_HEIGHT;
        if (snake_is_ocupy(snake, fruit->x_pos, fruit->y_pos)){
            spawn_col = 1;
        }
        else 
            spawn_col = 0;
    }
}

void fruit_render(struct fruit *fruit, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
    canvas[fruit->x_pos][fruit->y_pos] = -1;
}