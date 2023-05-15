#include "linkedlist.h"

struct node{
    struct pos pos;
    struct node *next;
    struct node *prev;
};

struct list_type{
   struct node *first; 
   struct node *last;
};

List list_initialize(){
    List list = malloc(sizeof(struct list_type));
    if (list == NULL)
        exit(EXIT_FAILURE);
    list->first = NULL;
    list->last = NULL;
    return list;
}

void list_add(List list, struct pos new_pos){
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        exit(EXIT_FAILURE);

    new_node->pos = new_pos;
    new_node->next = list->last;
    if (list->first == NULL){
        list->first = new_node;
    }
    else{
        list->last->prev = new_node;
    }
    new_node->prev = NULL;
    list->last = new_node;
}

//debug
void list_traverse(List list){
    struct node *cur;
    for (cur = list->last;
         cur != NULL;
         cur = cur->next){
        printf("x: %d\ty: %d\tprev:%p\tthis:%p\tnext:%p\n", 
                cur->pos.x_pos, cur->pos.y_pos, cur->prev, cur, cur->next);
    }
}

int list_search_if_exists(List list, struct pos search_pos){
    struct node *cur;
    for (cur = list->last;
         cur != NULL;
         cur = cur->next){
        if (cur->pos.x_pos == search_pos.x_pos && cur->pos.y_pos == search_pos.y_pos)
            return 1;
    }
    return 0;
}

struct pos list_exclude_first(List list){
    struct node *temp;
    struct pos excluded;
    temp = list->first->prev;
    excluded = temp->next->pos;
    free(temp->next);
    temp->next = NULL;
    list->first = temp;
    return excluded;
}

void list_fill_canvas(List list, char canvas[CANVAS_WIDTH][CANVAS_HEIGHT]){
    struct node *cur;
    for (cur = list->last;
         cur != NULL;
         cur = cur->next){
            canvas[cur->pos.x_pos][cur->pos.y_pos] = 1;
        }
}

void list_free(List list){
    struct node *cur, *prev;
    for (cur = list->last, prev = NULL;
         cur != NULL;
         prev = cur, cur = cur->next){
            free(prev);
        }
        free(cur);
        free(list);
}