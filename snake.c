#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "snake.h"
#include "engine.h"

struct snake initialize(){
	int i, j;
	struct snake snake;
	snake.size = 4;
	snake.x_pos = CANVAS_WIDTH / 2;
	snake.y_pos = CANVAS_HEIGHT / 2;
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			snake.canvas_ocupy[j][i] = 0;
		}
	}
	snake.canvas_ocupy[snake.x_pos][snake.y_pos] = snake.size;
	snake.keydir = RIGHT;
	snake.alive = 1;
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
	snake_is_alive(snake);
	snake->canvas_ocupy[snake->x_pos][snake->y_pos] = snake->size;
	return snake->keydir;
}

void snake_update_body(int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT]){
	int i, j;
	/*reduce snake positions by 1*/
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			if (canvas_ocupy[j][i] > 0);
				canvas_ocupy[j][i]--;
		}
	}
}

void snake_render(struct snake *snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
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

void snake_is_alive(struct snake *snake){
	// canvas borders colision detection
	if (snake->x_pos == CANVAS_WIDTH || snake->x_pos < 0 || 
		snake->y_pos == CANVAS_HEIGHT || snake->y_pos < 0)
		snake->alive = 0;
	// ideia: rewrite this to make the snake warp through the oposite side
	// snake's own body colision detection
	if (snake->canvas_ocupy[snake->x_pos][snake->y_pos] > 0)
		snake->alive = 0;
}