#ifndef FRUIT_H
#define FRUIT_H

#include "engine.h"
#include "snake.h"

struct fruit{
    int x_pos;
    int y_pos;
};

/*initialize fruit, put in a random spot on the canvas*/
struct fruit fruit_initialize();
/*respawn fruit*/
void fruit_respawn(struct fruit *fruit, Snake snake);
/*put the fruit on the canvas*/
void fruit_render(struct fruit *fruit, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]);

#endif