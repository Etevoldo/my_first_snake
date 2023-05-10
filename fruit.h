#ifndef FRUIT_H
#define FRUIT_H

#include "engine.h"

struct fruit{
    int x_pos;
    int y_pos;
};

struct fruit fruit_initialize(int snake_x_pos, int snake_y_pos);
void fruit_respawn(struct fruit *fruit, int snake_x_pos, int snake_y_pos);

#endif