#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    void* children[2];
} node;


node *addnode(node **current_node, int data, int child) {
    node *new = NULL;

    if (*current_node == NULL) {
        new = malloc(sizeof(node));
        printf("Malloc successful\n");
        if (new == NULL) {
            return NULL;
        }

        new->data = data;
        (*current_node)->children[child] = new;
        printf("child successfully added\n");
        new->children[0] = NULL;
        new->children[1] = NULL;
        printf("Malloc2 successful\n");
    }
    else {
        new = malloc(sizeof(node));
        printf("Malloc successful\n");
        if (new == NULL) {
            return NULL;
        }

        new->data = data;
        (*current_node)->children[child] = new;
        new->children[0] = NULL;
        new->children[1] = NULL;
        printf("Malloc2 successful\n");
    }

    return new;
}


void inorder(node * root) {
    if (root != NULL) {
        inorder(root->children[0]);
        printf("%d ", root->data);
        inorder(root->children[1]);
    }
}

/* A utility function to insert a new node with given key in BST */
node *insert(node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->children[0] = insert(node->children[0], key);
    else
        node->children[1] = insert(node->children[1], key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a binary search tree and a key, this function deletes the key and returns the new root */
node *deleteNode(node * root, int k) {
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (k < root->data) {
        root->children[0] = deleteNode(root->children[0], k);
        return root;
    }
    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (k > root->data) {
        root->children[1] = deleteNode(root->children[1], k);
        return root;
    }

    // If key is same as root's key, then this is the node to be deleted
    // Node with only one child or no child
    if (root->children[0] == NULL) {
        node *temp = root->children[1];
        free(root);
        return temp;
    }
    else if (root->children[1] == NULL) {
        node * temp = root->children[0];
        free(root);
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    node * succParent = root;
    node * succ = root->children[1];
    while (succ->children[0] != NULL) {
        succParent = succ;
        succ = succ->children[0];
    }

    // Copy the inorder successor's content to this node
    root->data = succ->data;

    // Delete the inorder successor
    if (succParent->children[0] == succ)
        succParent->children[0] = succ->children[1];
    else
        succParent->children[1] = succ->children[1];

    free(succ);
    return root;
}


int traversePreorder(node *root)  
{  
    if (root == NULL)  
        return -1;

    printf("%d->", root->data);
    traversePreorder(root->children[0]);
    traversePreorder(root->children[1]);

    return 1;
}  


void init_tree(node *head) {
    head->children[0] = NULL;
    head->children[1] = NULL;
}


int main() {
    node head;
    node *head_ptr = &head;
    node *new = NULL, *current_node = head_ptr;

    int input, input2, option;    

    init_tree(current_node);

    while(1) {
        input = 0;
        input2 = 0;
        option = 0;

        printf("1.Add node\n2.Remove node\n3.insert new node\n4.Print and quit\n");
        scanf("%d", &option);

	printf("hi\n");	

        switch (option) {
            case 1:

                printf("Data?\n");
                scanf("%d", &input);

                printf("Child?\n");
                scanf("%d", &input2);

                current_node = addnode(&current_node, input, input2);

                printf("%p, %d\n", head_ptr->children[0], current_node->data);

                break;
            case 2:

                break;
            
            case 4:
                traversePreorder(head_ptr);
                printf("\n");

                return 0;
            default:
                printf("Fuck u\n");
                break;
        }
    }

    // printf("%p, %p\n", head_ptr->children[0], head_ptr->children[1]);

    // new = addnode(&head_ptr, 2, 0);

    // printf("%p, %d\n", head_ptr->children[0], new->data);

    // new = addnode(&new, 3, 0);

    // printf("%p, %p\n", head_ptr->children[0], new);

    return 0; 
}
