// https://www.youtube.com/watch?v=dti0F7w3yOQ&t=621s

#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

node *head = NULL;

void printlist() {
    node *current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }

    printf("\n");
    return;
}


int main(int argc, char *argv[]) {
    int option = 0, input = 0, input2 = 0;

    while (option != 4) {
        node *new = NULL;
        printf("1.Add node\n2.Remove node\n3.insert new node\n4.quit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("data?\n");
                scanf("%d", &input);

                new = addnode(&head, input);

                printlist();

                printf("hi!!!\n");

                option = 0;
                break;
            case 2:
                printf("data to remove?\n");
                scanf("%d", &input);

                int success = remove_node_by_position(&head, input);
                
                if (!success) {
                    printf("WOMP WOMP\n");
                    printlist();
                }

                printlist();

                option = 0;
                break;
            
            case 3:
                printf("data to insert?\n");
                scanf("%d", &input);

                printf("position to insert?\n");
                scanf("%d", &input2);

                new = insertnode(&head, input, input2);
                
                if (new == NULL) {
                    printf("WOMP WOMP\n");
                    printlist();
                }

                printlist();

                option = 0;
                break;
            case 4:
                break;

            default:
                printf("ur a fucking failure\n");
        }
    }
    exit(0);
}