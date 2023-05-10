#ifndef ENGINE_H
#define ENGINE_H

#define clrscr() printf("\033[H\033[J")
#define CANVAS_HEIGHT 15
#define CANVAS_WIDTH 40

/*render a frame*/
void scrdraw(char key);
/*main engine the computes the logit of every frame 
  based on information about the snake and fruit objects*/
void start();

#endif