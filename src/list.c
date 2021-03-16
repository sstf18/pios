/*--list.c*/
#include <stddef.h>
#include "list.h"
/*
 * listAdd
 * adds newElement to a linkedList pointed to by list. when calling this function,
 * pass the address of list head.  
 * */
void list_add(struct listElement** head, struct listElement *newElement)
{
	struct listElement *iterator = (struct listElement*)head; 
	
	//Link element b into the list between iterator and iterator 
	newElement->next = iterator-> next;
	newElement->prev = iterator; 
	
	iterator->next = newElement; 
		
	if(newElement->next != NULL){
			newElement->next->prev = newElement; 
	} 
} 

/*
 * list delete
 * deletes an element from a doubly linked list
 * */
void list_remove(struct listElement *b) 
{ 
	if(b->next != NULL){
			b->next->prev = b->prev;
	}	
	b->prev->next = b->next; 
	
	//NULLify the element's next and prev pointers to indicae
	//that it is not linked into a list.  
	b->next = NULL;
	b->prev = NULL;

}	
	
		

