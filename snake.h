#ifndef SNAKE_H
#define SNAKE_H
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#include "engine.h"

struct snake{
	int size;
	int x_pos;
	int y_pos;
	char keydir;
	/*space ocupied by the snake's body*/
	int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT];
	int alive;
};
/*initialize a snake object*/
struct snake initialize();
/*recieve a user input, move the snake position and decrease body positions*/
char snake_move(struct snake *snake);
/*update the canvas array to fit the snake locations*/
void render_snake(struct snake *snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]);
/*reduce body lenght*/
void snake_update_body(int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT]);
/*detect if the snake died, return 1 if its alive*/
void snake_is_alive(struct snake *snake);
#endif