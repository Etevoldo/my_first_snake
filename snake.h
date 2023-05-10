#ifndef SNAKE_H
#define SNAKE_H

#define CANVAS_HEIGHT 15
#define CANVAS_WIDTH 40
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

struct snake{
	int size;
	int x_pos;
	int y_pos;
	char keydir;
	int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT];
};

struct snake initialize();

char snake_move(struct snake *snake);
void render_snake(struct snake *snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]);
#endif