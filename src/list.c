/*--list.c*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void list_add(struct list_element** head_ref, int new_data)
{
	struct list_element new_element;
	struct list_element *last = *head_ref;
	new_element.data = new_data;
	new_element.next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = &new_element;
		return;
	}
	while(last->next != NULL){
		last = last->next;
	}
	last->next = &new_element;
	return;
} 
void list_remove(struct list_element** head_ref, int data) 
{ 
	struct list_element* temp = *head_ref, *prev;
	
	if(head_ref != NULL && temp->data ==data) {
		*head_ref = temp->next;
		return;  
	}
	
	while(temp != NULL && temp->data != data){
		prev = temp; 
		temp = temp->next;
	}
	if (temp == NULL){
		prev->next = temp->next;
	}

}	
	
		

