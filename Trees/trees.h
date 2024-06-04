typedef struct _node{
    int data;
    struct _node *left;
    struct _node *right;
} node;

typedef struct {
    int top;
    void *array[];
} out_array;

node *insert(node **root, int data);
node *addnode(node **current_node, int data, int child);
node *inorder_search(node *root, int data);
int inorder_discover(node *root, out_array *array);
void inorder_count(node *root, int *counter, int data);
void inorder_print(node *root);
void delete(node **parent, int child);
void init_tree(node *head);
