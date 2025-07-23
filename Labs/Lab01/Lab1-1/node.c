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
// 
void insert_node_after(list *lst, int index, char *word)
{
	// TODO
	
	node *new_node = (node *)malloc(sizeof(node));
	new_node->word = (char *)malloc(strlen(word)+1);
	// save to the destination
	strcpy(new_node->word, word);
	if (lst->head == NULL){
		lst->head = new_node;
		new_node->next = lst->head;

	}
	node* curr_node = lst->head;

	if (index <0){
		// get the size of the index 
		int size = 0;
		node* temp =  curr_node;
		while (temp->next != lst->head){
			size++;
			temp = temp->next;
		}
		index = size + index;

	}
		printf("%s\n","Indexes are above 0");
		int curr_pos = 0;
		
		while (curr_pos < index && curr_node->next != lst->head){
			curr_node = curr_node->next;
			curr_pos += 1;
		}
		
		new_node->next = curr_node->next;
		new_node->prev = curr_node;
		curr_node->next = new_node;
	

}
	/*
	
	
	*/


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
