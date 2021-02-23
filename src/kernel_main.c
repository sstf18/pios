
#include "list.h"
#include <stdio.h>
#include "led.h"

extern long __bss_start;
extern long __bss_end;

void clear_zero();

void kernel_main() {
	
	clear_zero();

	led_init();	
	while(1){
		led_on();
		delay(300);
		led_off();
		delay(300);
						
	}  
  
}
/*
struct list_element c = {NULL, 0};
struct list_element b = {&c, 0};
struct list_element a = {&b, 0};
struct list_element *head = &a;
*/

//hw1
void clear_zero(){

	int x = 0; 
	while((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0; 
		x++;
	}
}

//in class activity
unsigned long get_timer_count(){
		unsigned long *timer_count_register = 0x3f003004;
		return *timer_count_register;
}

/*
unsigned int el; 
asm("mrs %0, CurrentEL"
	: "=r" (el)
	:
	:);
*/
