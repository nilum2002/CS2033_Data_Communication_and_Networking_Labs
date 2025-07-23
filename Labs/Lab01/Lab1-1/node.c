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
	if (new_node == NULL){
		return; // Handle memory allocations failures 
	}
	new_node->word = (char *)malloc(strlen(word)+1);
	strcpy(new_node->word, word);
	if (lst->head == NULL){
		
		lst->head = new_node;
		// get the circular doubly linked list properties 
		new_node->next = new_node;
		new_node->prev = new_node;
		return;

	}
	// get the size
	int size = 0;
	node *temp = lst->head;
	while (temp->next != lst->head){
		temp = temp->next;
		size++;
	}
	if (index<0){
		index = size+index;
	}
	
	

	// find the right index 
	node *curr_node = lst->head;

	int count = 0;
	while (count < index && curr_node->next != lst->head){
		curr_node = curr_node->next;
		count++;
	}
	// the actual node 
	node *pre = curr_node;
	// post node 
	node *post = curr_node->next;

	new_node->prev = pre;
	pre->next = new_node;
	new_node->next = post;
	post->prev = new_node;
	
	
	
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
