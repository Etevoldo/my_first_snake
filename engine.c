#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "snake.h"
#include "engine.h"

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
	char key;
	snake = initialize();
	while (1){
		sleep(1);
		key = snake_move(&snake);
		render_snake(&snake, canvas);
		scrdraw(key);
		//debug
		printf("\nx:%d y:%d size:%d\n", snake.x_pos, snake.y_pos, snake.size);
		if (key == 'q')
			break;
	}
}
