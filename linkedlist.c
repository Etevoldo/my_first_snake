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
    if (list->first == NULL)
        list->first = new_node;
    list->last = new_node;
}

//debug
void list_traverse(List list){
    struct node *cur;
    for (cur = list->last;
         cur != NULL;
         cur = cur->next){
        printf("x: %d\ty: %d\n", cur->pos.x_pos, cur->pos.y_pos);
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