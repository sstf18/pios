
#include "list.h"
#include <stdio.h>

extern long __bss_start;
extern long __bss_end;

void clear_zero();

void kernel_main() {
	while(1){
	}
	clear_zero();
   
  
}
/*
struct list_element c = {NULL, 0};
struct list_element b = {&c, 0};
struct list_element a = {&b, 0};
struct list_element *head = &a;
*/
void clear_zero(){

	int x = 0; 
	while((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0; 
		x++;
	}
}
