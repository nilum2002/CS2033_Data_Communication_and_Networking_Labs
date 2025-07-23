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
    char  input[100];
    fgets(input, sizeof(input), stdin);

    char *token;
    token = strtok(input, ","); 
    int count  = 1;

    while (token){
        insert_node_after(lst, count, token);
        
        count++;
        token = strtok(NULL, ",");
        
    }
    while(1){
        // get the instruction type
        int type;
        scanf("%d", &type);
        // get the index
        int index; 
        scanf("%d", &index);

        // get the word 
        char word[MAX_WORD_LENGTH];
        scanf("%s", word);

        if (type == INSERT_AFTER){
            insert_node_after(lst, index, word);
        }
        break;





     }

    
}
// Print the list contents
void print_list(list *lst)
{
    printf("%s\n","working on print");
    node *curr = lst->head;
    



    do {
        printf("%s", curr->word);

        curr = curr->next;
    } while (curr != lst->head);
}
