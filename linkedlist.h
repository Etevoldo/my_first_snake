#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "engine.h"

typedef struct list_type *List;

List list_initialize();
void list_add(List list, struct pos new_pos);
void list_traverse(List list);

#endif