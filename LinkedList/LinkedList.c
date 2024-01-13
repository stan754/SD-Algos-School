//
// Created by stan754 on 31-3-23.
//

#include "LinkedList.h"
#include <stdio.h>

int PrintList(node_t *head) {
    if (head == NULL) {
        return -1;
    }

    node_t *current = head;

    while (current != NULL) {
        printf("%d\n", *((uint8_t*)current->data));
        current = current->next;
    }
    return 0;
}

int AddItemToEnd(node_t *head, void *data) {
    if (head == NULL) {
        return -1;
    }

    node_t *newNode = NULL;
    newNode = (node_t *) malloc(sizeof(node_t));

    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;

    node_t *last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;

    return 0;
}

int AddItemToStart(node_t **head, void* data) {
    if (head == NULL) {
        return -1;
    }

    node_t *newNode = NULL;
    newNode = (node_t *) malloc(sizeof(node_t));

    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;

    return 0;
}

int AddItemToIndex(node_t **head, void *data, uint8_t index) {
    if (head == NULL) {
        return -1;
    }

    node_t *newNode = NULL;
    newNode = (node_t *) malloc(sizeof(node_t));

    if (newNode == NULL) {
        return -1;
    }

    newNode->data = data;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return 0;
    }

    node_t *current = *head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) {
            free(newNode);
            return -1;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return 0;
}


int RemoveItem(node_t **head, uint8_t index) {
    if (head == NULL) {
        return -1;
    }

    node_t *tmp = *head;
    node_t *previous = *head;

    for(int i = 0; i < index; i++) {
        if (i == 0 && index == 1) {
            *head = (*head)->next;
        }
        if (i == index - 1 && tmp) {
            previous->next = tmp->next;
            free(tmp);
        } else {
            previous = tmp;
            if (previous == NULL || tmp == NULL) {
                break;
            }
            tmp = tmp->next;
        }
    }

    return 0;
}

int FreeList(node_t *head) {
    if (head == NULL) {
        return -1;
    }

    node_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}