#ifndef __LIST_H
#define __LIST_H
struct listElement {
	struct listElement *next;
	struct listElement *prev;
	
};

void list_add(struct listElement** head, struct listElement *newElement);
void list_remove(struct listElement *b); 
#endif
