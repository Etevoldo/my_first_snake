#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include "engine.h"
#include "fruit.h"
#include "snake.h"

int debugloop = 0;

char canvas[CANVAS_WIDTH][CANVAS_HEIGHT] = {{0}, {0}};
void scrdraw(char key){
	int i, j;
	clrscr();
	//debug
	printf("counter of frames: %d, last key: %c\n", debugloop++, key);
	printf("##########################################\n");
	for (i = 0; i < CANVAS_HEIGHT; i++){
		printf("#");
		for (j = 0; j < CANVAS_WIDTH; j++){
			printf("%c", (canvas[j][i] == 1) ? '0' : ' ');
		}
		printf("#\n");
	}
	printf("##########################################\n");

}

void start(){
	int i, j;
	struct snake snake;
	struct fruit fruit;
	char key;
	snake = initialize();
	fruit = fruit_initialize(snake.x_pos, snake.y_pos);
	while (1){
		Sleep(300);
		key = snake_move(&snake);
		if (ate(fruit.x_pos, fruit.y_pos, snake.x_pos, snake.y_pos))
			fruit_respawn(&fruit, snake.x_pos, snake.y_pos);
		render_snake(&snake, canvas);
		fruit_render(&fruit, canvas);
		scrdraw(key);
		//debug
		printf("\nsx:%d y:%d size:%d\n", snake.x_pos, snake.y_pos, snake.size);
		printf("xf:%d yf:%d\n", fruit.x_pos, fruit.y_pos);
		if (key == 'q')
			break;
	}
}

int ate(int fruit_x_pos, int fruit_y_pos, int snake_x_pos, int snake_y_pos){
	if (fruit_x_pos == snake_x_pos && fruit_y_pos == snake_y_pos)
		return 1;
	else 
		return 0;
}