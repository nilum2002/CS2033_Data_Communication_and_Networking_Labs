// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <string.h>


// user-defined header files
#include "node.h"

// macros

#define INSERT_BEFORE 1
#define INSERT_AFTER 2
#define DELETE_NODE 3
#define DELETE_LIST 4

// function prototypes
void print_list(list *lst);
void run(list *lst);

int main()
{
    list *lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    run(lst);
    print_list(lst);
    free(lst);
    return 0;
}

// parse the input
void run(list *lst)
{
    // get the first line of input
    char input[100];
    fgets(input, sizeof(input), stdin);

    char *token;
    token = strtok(input, ",");

    // Build initial list by always inserting at the end
    while (token) {
        // Remove newline if present
        char *newline = strchr(token, '\n');
        if (newline) *newline = '\0';
        
        insert_node_after(lst, -1, token);  // Always insert at end
        token = strtok(NULL, ",");
    }
    while(1){
        // get the instruction type
        int type;
        scanf("%d", &type);

        if (type == 0) {
            break;
        }
        else if (type == 1 || type == 2) {
            int position;
            char word[50];
            scanf("%d %s", &position, word);

            if (type == 1) {
                insert_node_before(lst, position, word);
            }
            else {
                insert_node_after(lst, position, word);
            }
        }
        else if (type == 3) {
            int position;
            scanf("%d", &position);
            delete_node(lst, position);
        }
        else if(type == 4)
            delete_list(lst);
    }

}
// Print the list contents
void print_list(list *lst)
{
    
    
    node *curr = lst->head;
    



    do {
        printf("%s ", curr->word);

        curr = curr->next;
    } while (curr != lst->head);
   
}