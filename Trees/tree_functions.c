#include <stdio.h>
#include <stdlib.h>

#include "trees.h"


node *insert(node **root, int data) {
    node *new = (node *) malloc(sizeof(node));
    if (*root == NULL) {
        return NULL;
    }
    
    if (!((*root)->left) && data < (*root)->data) {
        new->data = data;
        init_tree(new);

        new->left = (*root)->left;        
        (*root)->left = new;

        return new;
    }
    else if (!((*root)->right)) {
        new->data = data;
        init_tree(new);

        new->right = (*root)->right;
        (*root)->right = new;
        
        return new;
    }

    if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
    else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    }

    return new;
}


node *addnode(node **current_node, int data, int child) {
    node *new = NULL;

    if (*current_node == NULL) {
        new = malloc(sizeof(node));
        if (new == NULL) {
            return NULL;
        }

        new->data = data;

        if (child == 0)
            (*current_node)->left = new;
        else
            (*current_node)->right = new;

        new->left = NULL;
        new->right = NULL;
    }
    else {
        new = malloc(sizeof(node));
        if (new == NULL) {
            return NULL;
        }

        new->data = data;
        
        if (child == 0)
            (*current_node)->left = new;
        else
            (*current_node)->right = new;

        new->left = NULL;
        new->right = NULL;
    }

    return new;
}


void inorder_print(node *root) {
    if (root != NULL) {
        inorder_print(root->left);
        printf("%d ", root->data);
        inorder_print(root->right);
        
    }
}


void inorder_count(node *root, int *counter, int data) {
    if (root) {
        inorder_count(root->left, counter, data);
        (*counter)++;
        inorder_count(root->right, counter, data);
    }
}


int inorder_discover(node *root, out_array *array) {
    if (root) {
        inorder_discover(root->left, array);
        inorder_discover(root->right, array);
        array->array[array->top] = root;
        printf("array[0]: %p\n", root);
        (array->top)++; 

    }
    else
        return 0;
}


node *inorder_search(node *root, int data) {
    if (root && root->data != data) {
        inorder_search(root->left, data);
        inorder_search(root->right, data);
    }
    else if (root && root->data == data) {
        return root;
    }
}


void generate_node_list(node *node_array, int tree_size) {
    
    printf("%d\n", inorder_discover);
}


// 0 is left child, 1 is right child
void delete(node **parent, int child) {
    node *deleteme = (child == 0) ? (*parent)->left : (*parent)->right;
    
    if (!deleteme) {
        return;
    }
    
    // case where deletme is a leaf node
    if (!(deleteme->left) && !(deleteme->right)) {
        if (child == 0)
            (*parent)->left = NULL;
        else
            (*parent)->right = NULL;
        
        free(deleteme);
        return;
    }

    // case where deletme is an only child
    // make the parent point to deleteme's left child
    if (!(deleteme->left)) {
        if (child)
            (*parent)->right = deleteme->right;
        else
            (*parent)->left = deleteme->right;
        
        free(deleteme);
        return;
    }
    else if (!(deleteme->right)) {
        if (child)
            (*parent)->right = deleteme->left;
        else
            (*parent)->left = deleteme->left;
        
        free(deleteme);
        return;
    }

    // case where deletme is parent of two children
    // make deletme' parent point to  it's left successor
    if (deleteme->left && deleteme->right) {
        if (child) {
            (*parent)->right = deleteme->left;
        }
        else {
            (*parent)->left = deleteme->left;
        }
        // TODO:
        //    replace deleteme with it's inorder successor
        //    in order to do that, u gotta generate a list of nodes with the inorder algorithm

        free(deleteme);
        return;
    }
    
}


void init_tree(node *head) {
    head->left = NULL;
    head->right = NULL;
}
