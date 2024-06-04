#ifndef SINGLY_LINED_LIST

#define SINGLY_LINED_LIST

typedef struct {
    int data;
    void *next;
} node;

node *addnode(node **new_head, int data);
int remove_node_by_position(node **head, int node_position);
int remove_node_by_data(node **head, int node_number);
node *insertnode(node **head, int data, int position);

#endif