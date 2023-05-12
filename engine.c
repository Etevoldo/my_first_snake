#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include "engine.h"
#include "fruit.h"
#include "snake.h"


char canvas[CANVAS_WIDTH][CANVAS_HEIGHT] = {{0}, {0}};
void scrdraw(char key){
	int i, j;
	clrscr();
	//debug
	for (i = 0; i < CANVAS_WIDTH + 2; i++){
		printf("#");
	}
		printf("\n");
	for (i = 0; i < CANVAS_HEIGHT; i++){
		printf("#");
		for (j = 0; j < CANVAS_WIDTH; j++){
			switch (canvas[j][i]){
				case 0:
					printf("%c", ' ');
					break;
				case -1:
					printf("%c", 'F');
					break;
				default:
					printf("%c", '0');
					break;
			}
		}
		printf("#\n");
	}
	for (i = 0; i < CANVAS_WIDTH + 2; i++){
		printf("#");
	}
		printf("\n");

}

void start(){
	int i, j, snake_size = 4, debugloop = 0;
	Snake snake;
	struct fruit fruit;
	struct pos snake_pos;
	char key;
	snake = initialize();
	snake_pos = snake_positions(snake);
	fruit = fruit_initialize();
	while (1){
		Sleep(400);
		key = snake_move(snake);
		snake_pos = snake_positions(snake);
		if (ate(fruit.x_pos, fruit.y_pos, snake_pos)){
			snake_increase(snake);
			snake_size++; //updating internal variable for debugging purpurses
			fruit_respawn(&fruit, snake);
		}
		else
			snake_update_body(snake);
		snake_render(snake, canvas);
		fruit_render(&fruit, canvas);
		scrdraw(key);
		//debug
		printf("counter of frames: %d, last key: %c\n", debugloop++, key);
		printf("\nsnake x:%d snake y:%d size:%d alive:%d\n",
				 snake_pos.x_pos, snake_pos.y_pos, snake_size, snake_is_alive(snake));
		printf("fruit x:%d fruit y:%d\n", fruit.x_pos, fruit.y_pos);
		if (!snake_is_alive(snake)){
		 	printf("You died!\n");
		 	printf("Press any key to continue");
			getch();
			break;
		}
		else if (snake_size == 32){
			printf("fez ai hipotenusa ai, o triangulo retangulo\n");
		 	printf("Press any key to continue");
			getch();
			break;
		}
	}
}

int ate(int fruit_x_pos, int fruit_y_pos, struct pos snake_pos){
	if (fruit_x_pos == snake_pos.x_pos && fruit_y_pos == snake_pos.y_pos)
		return 1;
	else 
		return 0;
}