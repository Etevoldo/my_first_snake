#ifndef ENGINE_H
#define ENGINE_H

#define clrscr() printf("\033[H\033[J")
#define CANVAS_HEIGHT 15
#define CANVAS_WIDTH 40


void scrdraw(char key);
void start();

#endif