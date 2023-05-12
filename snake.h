#ifndef SNAKE_H
#define SNAKE_H
#define UP 'W'
#define DOWN 'S'
#define LEFT 'A'
#define RIGHT 'D'
#include "engine.h"

typedef struct snake_type *Snake;
/*
struct snake{
	int size;
	int x_pos;
	int y_pos;
	char keydir;
	int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT];
	int alive;
};
*/

/*initialize a snake object*/
Snake initialize();
/*recieve a user input, move the snake position and decrease body positions*/
char snake_move(Snake snake);
/*update the canvas array to fit the snake locations*/
void snake_render(Snake snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]);
/*reduce body lenght*/
void snake_update_body(Snake snake);
/*detect if the snake died*/
void snake_update_live(Snake snake);
/*boolean function to return living status of the snake*/
int snake_is_alive(Snake snake);
/*helper function to check if we are trying to go backyards*/
int snake_reverse_key(int key);
/*function to return the snake positions*/
struct pos snake_positions(Snake snake);
/*first argument is the snake in question, and the
  other two are positions to check if the space if ocupied*/
int snake_is_ocupy(Snake snake, int x_pos, int y_pos);

void snake_increase(Snake snake);
#endif