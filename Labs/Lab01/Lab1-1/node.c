// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h> // includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:


// implementation
void insert_node_before(list *lst, int index, char *word)
{	
	// TODO
	

}

void insert_node_after(list *lst, int index, char *word)
{
	// TODO
	// crate a new node
	node *new_node = (node*)malloc(sizeof(MAX_WORD_LENGTH));
	if (lst == NULL ){
		new_node->word = word;
		new_node->prev = lst->head;
		new_node->next = NULL;
		lst->head = new_node;
	}else{
		node* curr = lst->head;
		int i = 0;
		while (i < index){
			curr = curr->next;
			i++;
		}
		new_node->word = word;
		new_node->prev = curr;
		new_node->next = curr->next;
	}
}

char *list_to_sentence(list *lst)
{
	// TODO
    return NULL; // Change this line accordingly
}

void delete_node(list *lst, int index)
{
	// TODO
}

void delete_list(list *lst)
{
	// TODO
}
