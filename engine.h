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
/*detect if the snake has bitten the fruit*/
int ate(int fruit_x_pos, int fruit_y_pos, int snake_x_pos, int snake_y_pos);

#endif