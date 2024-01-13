//
// Created by stan754 on 31-3-23.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "stdint.h"

typedef struct node{
    void *data;
    struct node* next;
} node_t;

int PrintList(node_t *head);
int AddItemToEnd(node_t *head, void *data);
int AddItemToStart(node_t **head, void *data);
int AddItemToIndex(node_t **head, void *data, uint8_t index);
int RemoveItem(node_t **head, uint8_t index);
int FreeList(node_t *head);

#endif //LINKEDLIST_LINKEDLIST_H
