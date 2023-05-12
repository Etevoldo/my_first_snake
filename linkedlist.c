#include <stdlib.h>
#include "linkedlist.h"

struct node{
    struct pos pos;
    struct node *next;
};

struct list_type{
   struct node *first; 
   struct node *last;
};

List list_initialize(){
    List list = malloc(sizeof(struct list_type));
    if (list == NULL)
        exit(EXIT_FAILURE);
    list->first->next = NULL;
    list->last->next = NULL;
    return list;
}

void list_add(List list, struct pos new_pos){
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        exit(EXIT_FAILURE);

    new_node->pos = new_pos;
    new_node->next = list->last;
    if (list->first == NULL)
        list->first = new_node;
    list->last = new_node;
}
/*
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
*/