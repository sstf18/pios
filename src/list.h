struct list_element {
	struct list_element *next;
	int data;
};

void list_add(struct list_element** head_ref, int new_data);
void list_remove(struct list_element** head_ref, int data) ;
