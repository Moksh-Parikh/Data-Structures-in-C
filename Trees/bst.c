#include <stdio.h>
#include <stdlib.h>

#include "trees.h"


int main(int argc, char **argv[]) {
    int option;
    int input, input2, count = 0;
    /* node *out_array[50]; */
    /* node *ptr_array = &(out_array[0]); */
    
    /* printf("%d\n", out_array[0]); */
    node head = {100};
    node *head_ptr = &head;
    node *current_node = head_ptr;
    
    out_array out;
    out.top = 0;
     
    init_tree(head_ptr);

    while (option != 6) {
        option = 0;
	    count = 0;
        /* out_array[0] = &top; */

        printf("1.Insert\n2.Delete\n3.Print\n4.Add (debug only)\n5.Search\n6.Exit\n");
        scanf("%d", &option);

        /*
            This builds the following tree:
                            100
                           /   \
                          1     2
                         / \   / \
                        0  69 \0 \0
                          /  \
                         \0  \0
        */

        current_node = addnode(&head_ptr, 1, 0);
        current_node = addnode(&head_ptr, 2, 1);
        // current_node = addnode(&(head_ptr->left), 1, 0);
        printf("%d, %d\n", sizeof(node), sizeof(node *));
        
        printf("added nodes\n");
        inorder_print(head_ptr);
        printf("\n");
        current_node = insert(&(head_ptr->left), 69);
        current_node = insert(&(head_ptr->left), 0);
        // current_node = addnode(&(current_node))
        printf("inserted nodes\n");
        inorder_print(head_ptr);
        // printf("\n");
        // scanf("%d", &option);
        // // printf("deleting...\n");
        // delete(&(head_ptr), 0);
        printf("Tree: ");
        inorder_print(head_ptr);
        printf("\n");
        inorder_discover(head_ptr, &out);
        
        for (int i = 0; i < 3; i++) {
            printf("%p, %d->", out.array[i], ((node *)out.array[i])->data);
        }

        /* inorder_count(head_ptr, &count, 1000); */
        /* printf("Count: %d\n", count); */

        // switch (option) {
        //    case 1:
        //        printf("Data?\n");
//                scanf("%d", &input);
// 
//                current_node = insert(&(head_ptr->left), input);
//                break;
//
//            case 2:
//                 delete(&(head_ptr->left), 0);
//                 break;
//
//          case 3:
//              inorder_print(head_ptr);
//              break;
//
//          case 4:
//              printf("Data?\n");
//              scanf("%d", &input);
//
//              printf("Child?\n");
//              scanf("%d", &input2);
//
//              current_node = addnode(&current_node, input, input2);
//
//              printf("%p, %d\n", head_ptr->left, current_node->data);
//              break;
//
//           case 5:
//              printf("Data?\n");
//              scanf("%d", &input);
//
//              printf("\n%d\n", (inorder(head_ptr, input))->data);            
//              break;
//  
//           case 6:
//               break;
//
//           default:
//               break;
//    	}
    }
}
