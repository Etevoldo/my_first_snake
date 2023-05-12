#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "snake.h"
#include "engine.h"

struct snake_type{
	int size;
	struct pos pos;
	/*
	int x_pos;
	int y_pos;
	*/
	char keydir;
	int canvas_ocupy[CANVAS_WIDTH][CANVAS_HEIGHT];
	int alive;
};


Snake initialize(){
	int i, j;
	Snake snake = malloc(sizeof(struct snake_type));
	if (snake == NULL)
		exit(EXIT_FAILURE);
	snake->size = 4;
	snake->pos.x_pos = CANVAS_WIDTH / 2;
	snake->pos.y_pos = CANVAS_HEIGHT / 2;
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			snake->canvas_ocupy[j][i] = 0;
		}
	}
	snake->canvas_ocupy[snake->pos.x_pos][snake->pos.y_pos] = snake->size;
	snake->keydir = RIGHT;
	snake->alive = 1;
	return snake;
}

char snake_move(Snake snake){
	int i, j, cur_key;
	if (kbhit()){
		cur_key = toupper(getch());
		if (cur_key == UP || cur_key == DOWN || cur_key == LEFT || cur_key == RIGHT){
			if (snake->keydir != snake_reverse_key(cur_key) && snake->keydir != cur_key){
				snake->keydir = cur_key;
			}
		}
	}
	switch (snake->keydir){
		case UP:
			snake->pos.y_pos--;
			break;
		case DOWN:
			snake->pos.y_pos++;
			break;
		case RIGHT:
			snake->pos.x_pos++;
			break;
		case LEFT:
			snake->pos.x_pos--;
			break;
	}
	snake_is_alive(snake);
	snake->canvas_ocupy[snake->pos.x_pos][snake->pos.y_pos] = snake->size;
	return snake->keydir;
}

void snake_update_body(Snake snake){
	int i, j;
	/*reduce snake positions by 1*/
	for (i = 0; i < CANVAS_HEIGHT; i++){
		for (j = 0; j < CANVAS_WIDTH; j++){
			if (snake->canvas_ocupy[j][i] > 0);
				snake->canvas_ocupy[j][i]--;
		}
	}
}

void snake_render(Snake snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
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

int snake_is_alive(Snake snake){
	// canvas borders colision detection
	if (snake->pos.x_pos == CANVAS_WIDTH || snake->pos.x_pos < 0 || 
		snake->pos.y_pos == CANVAS_HEIGHT || snake->pos.y_pos < 0)
		snake->alive = 0;
	// ideia: rewrite this to make the snake warp through the oposite side
	// snake's own body colision detection
	if (snake->canvas_ocupy[snake->pos.x_pos][snake->pos.y_pos] > 0)
		snake->alive = 0;
	if (snake->alive == 0)
		return 0;
	else 
		return 1;
}

int snake_reverse_key(int key){
	switch (key){
		case 'W':
			return 'S';
			break;
		case 'S':
			return 'W';
			break;
		case 'A':
			return 'D';
			break;
		case 'D':
			return 'A';
			break;
	}
}

struct pos snake_positions(Snake snake){
	return snake->pos;
}

int snake_is_ocupy(Snake snake, int x_pos, int y_pos){
	if (snake->canvas_ocupy[x_pos][y_pos] > 0)
		return 1;
	else 
		return 0;
}

void snake_increase(Snake snake){
	snake->size++;
}