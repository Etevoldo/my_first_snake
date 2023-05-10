#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "snake.h"
#include "engine.h"

struct snake initialize(){
	int i, j;
	struct snake snake;
	snake.size = 8;
	snake.x_pos = 10;
	snake.y_pos = 20;
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			snake.canvas_ocupy[j][i] = 0;
		}
	}
	snake.canvas_ocupy[snake.x_pos][snake.y_pos] = snake.size - 1;
	snake.keydir = RIGHT;
	return snake;
}

char snake_move(struct snake *snake){
	int i, j;
	if (kbhit()){
		snake->keydir = getch();
	}
	switch (snake->keydir){
		case UP:
			snake->y_pos--;
			break;
		case DOWN:
			snake->y_pos++;
			break;
		case RIGHT:
			snake->x_pos++;
			break;
		case LEFT:
			snake->x_pos--;
			break;
	}
	snake->canvas_ocupy[snake->x_pos][snake->y_pos] = snake->size;

	/*reduce snake positions by 1*/
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			if (snake->canvas_ocupy[j][i] > 0);
				snake->canvas_ocupy[j][i]--;
		}
	}
	return snake->keydir;
}

void render_snake(struct snake *snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
	int i, j;
	
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			if (snake->canvas_ocupy[j][i] > 0) 
				canvas[j][i] = 1;
			else
				canvas[j][i] = 0;
		}
	}
}