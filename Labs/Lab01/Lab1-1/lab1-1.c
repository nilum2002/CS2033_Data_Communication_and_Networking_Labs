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
    int count  = 0;

    while (token){
        insert_node_after(lst, count, token);
        printf("%s", token);
        count++;
        token = strtok(NULL, ",");
        
    }

    
}
// Print the list contents
void print_list(list *lst)
{
    printf("working");
    
    print_list(lst);

}
