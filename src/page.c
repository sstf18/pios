/*--page.c
 * 
 * code form Neil's instructions*/
#include "list.h"
#include "page.h"
#define NPAGES 128
#define NULL (void*)0
extern int __end; 

//statically allocate an array of struct ppages
struct ppage physical_page_array[NPAGES]; //128 pages, each 2mb in length covers 256 megs of memory
struct ppage* free_list = NULL; 

//initializes the list of free physical page structures
//initialize the linked list of free pages. 
//loop through "physical_page_array", and link it into the list.
void init_pfa_list(void){			
		void* address_p = (((unsigned long)&__end) & ~(0x200000 -1)) +0x200000;	
		//void* address_p = 0x200000; 
		int x; 
		for (x=0; x<NPAGES; x++){
				list_add(&free_list, (struct listElement*) &physical_page_array[x]);
				physical_page_array[x].physical_addr = address_p;
				address_p += 0x200000;
		}
}
	
//allocate and free physical pages
//allocator are going to call list.c functions to link elements and unlink elements.
//allocate physical pages from the list of free pages. then input to fucntion.
//npages specifies the number of pages to allocate.
//unlink number pages form free list, and create a seprate list(return pointer to "allocd_list") 
struct ppage *allocate_physical_pages(unsigned int npages){
		struct ppage* new_var = free_list;
		struct ppage* allocatedList = NULL;
		int x;
		for (x = 0; x< npages; x++ ){
				list_remove(new_var);
				list_add(&allocatedList, new_var);			
		}		
		return allocatedList;
	
}

//return a list of physical pages to the free list. 
void free_physical_pages(struct ppage *ppage_list){
	struct ppage* new_var = ppage_list;
	while (ppage_list != NULL){
			list_remove(new_var);
			list_add(&free_list, new_var);
	}
	
}

