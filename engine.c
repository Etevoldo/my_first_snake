#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include "snake.h"
#include "engine.h"

#define UP = 'w'
#define DOWN = 's'
#define LEFT = 'a'
#define RIGHT = 'd'
#define CANVAS_HEIGHT 15
#define CANVAS_WIDTH 40

char key;
int debugloop = 0;

char canvas[CANVAS_HEIGHT][CANVAS_WIDTH] = {{0}, {0}};
void scrdraw(){
    int i, j;
    clrscr();
    printf("counter of frames: %d, last key: %c\n", debugloop++, key);
    printf("##########################################\n");
    for (i = 0; i < CANVAS_HEIGHT; i++){
        printf("#");
        for (j = 0; j < CANVAS_WIDTH; j++){
            printf("%s", (canvas[i][j] == 1) ? "0" : " ");
        }
        printf("#");
        printf("\n");
    }
    printf("##########################################\n");

}

void render(){
    while (1){
        sleep(0.5);
        if (kbhit()){
            if ((key = getch()) == 'q')
                break;
        }
        scrdraw();
    }
}