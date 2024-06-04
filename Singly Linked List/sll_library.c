#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

node *addnode(node **new_head, int data) {
    node *new = NULL;

    if (*new_head == NULL) {
        new = malloc(sizeof(node));
        if (new == NULL) {
            return NULL;
        }

        new->data = data;
        *new_head = new;
        new->next = NULL;
    }
    else {
        new = malloc(sizeof(node));
        if (new == NULL) {
            return NULL;
        }

        new->data = data;
        new->next = *new_head;
        *new_head = new;
    }

    return new;
}

int remove_node_by_position(node **head, int node_position) {
    node *current = *head;
    node *previous = *head;
    int count = 0;

    while (current != NULL) {
        if (count == node_position) {
            if (current == *head) {
                *head = current->next;
            } 
            else {
                previous->next = current->next;
                free(current);
                current = NULL;
            }

            return 1;
        }
        previous = current;
        current = current->next;

        count++;
    }

    return 0;
}

int remove_node_by_data(node **head, int node_number) {
    node *current = *head;
    node *previous = *head;

    while (current != NULL) {
        if (current->data == node_number) {
            if (current == *head) {
                *head = current->next;
            } 
            else {
                previous->next = current->next;
                free(current);
                current = NULL;
            }

            return 1;
        }
        previous = current;
        current = current->next;

    }

    return 0;
}

node *insertnode(node **head, int data, int position) {
    node *current = *head;
    while (current != NULL && --position != 0) {
        current = current->next;
    }

    if (position != 0) {
        fprintf(stderr, "Position not possible\n");
        return NULL;
    }

    node *new = malloc(sizeof(node));

    if (new == NULL) {
        fprintf(stderr, "Error in insertnode(): malloc() failed");
        return NULL;
    }

    new->data = data;
    new->next = current->next;
    current->next = new;

    return new;
}
