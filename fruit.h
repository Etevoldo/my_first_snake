#ifndef FRUIT_H
#define FRUIT_H

#include "engine.h"

struct fruit{
    int x_pos;
    int y_pos;
};
/*initialize fruit, put in a random spot on the canvas*/
struct fruit fruit_initialize(int snake_x_pos, int snake_y_pos);
/*respawn fruit*/
void fruit_respawn(struct fruit *fruit, int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT]);
/*put the fruit on the canvas*/
void fruit_render(struct fruit *fruit, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]);

#endif