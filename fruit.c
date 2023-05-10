#include <stdlib.h>
#include <time.h>
#include "fruit.h"
#include "engine.h"

struct fruit fruit_initialize(int snake_x_pos, int snake_y_pos){
    srand((unsigned) time (NULL));
    struct fruit fruit;
    //check if there'll be an off by one error later
    fruit.x_pos = rand() % CANVAS_WIDTH;
    fruit.y_pos = rand() % CANVAS_HEIGHT;
    //todo: add a conditional to not spawn on the body
    return fruit;
}

void fruit_respawn(struct fruit *fruit, int snake_x_pos, int snake_y_pos){
    srand((unsigned) snake_x_pos + snake_y_pos);
    //check if there'll be an off-by-one error later
    fruit->x_pos = rand() % CANVAS_WIDTH;
    fruit->y_pos = rand() % CANVAS_HEIGHT;
    return;
}