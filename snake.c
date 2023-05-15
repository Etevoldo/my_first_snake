#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include "snake.h"
#include "engine.h"
#include "linkedlist.h"

struct snake_type{
	int size;
	struct pos pos;
	struct pos behind;
	char keydir;
	List canvas_ocupy;
	int alive;
};


Snake initialize(){
	int i, j;
	Snake snake = malloc(sizeof(struct snake_type));
	if (snake == NULL)
		exit(EXIT_FAILURE);
	snake->size = 1;
	snake->pos.x_pos = CANVAS_WIDTH / 2;
	snake->pos.y_pos = CANVAS_HEIGHT / 2;

	snake->canvas_ocupy = list_initialize();
	list_add(snake->canvas_ocupy, snake->pos);
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
	snake_update_live(snake);
	list_add(snake->canvas_ocupy, snake->pos);
	return snake->keydir;
}

//TODO: exclude the first item on the list
void snake_update_body(Snake snake){
	struct pos behind;
	snake->behind = list_exclude_first(snake->canvas_ocupy);
}

void snake_render(Snake snake, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
	int i, j;
	
	list_fill_canvas(snake->canvas_ocupy, canvas);
	canvas[snake->behind.x_pos][snake->behind.y_pos] = 0;
}

void snake_update_live(Snake snake){
	// canvas borders colision detection
	if (snake->pos.x_pos == CANVAS_WIDTH || snake->pos.x_pos < 0 || 
		snake->pos.y_pos == CANVAS_HEIGHT || snake->pos.y_pos < 0)
		snake->alive = 0;
	// ideia: rewrite this to make the snake warp through the oposite side
	// snake's own body colision detection
	if (list_search_if_exists(snake->canvas_ocupy, snake->pos))
		snake->alive = 0;
}

int snake_is_alive(Snake snake){
	if (!snake->alive)
		list_free(snake->canvas_ocupy);
	return snake->alive;
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
	struct pos search = {.x_pos = x_pos, y_pos = y_pos};
	if (list_search_if_exists(snake->canvas_ocupy, search))
		return 1;
	else 
		return 0;
}

void snake_increase(Snake snake){
	snake->size++;
}