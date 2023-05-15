#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "engine.h"
typedef struct list_type *List;

List list_initialize();
void list_add(List list, struct pos new_pos);
void list_traverse(List list);
/*boolean function to test if the position exists*/
int list_search_if_exists(List list, struct pos search_pos);
/* exclude first element of the list, return a position 
   to exclude from the rendering*/
struct pos list_exclude_first(List list);
/*fill array of snake positions*/
void list_fill_canvas(List list, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]);
void list_free(List list);
#endif