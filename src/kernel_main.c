
#include "list.h"
#include "led.h"
#include "rprintf.h"
#include "serial.h"

//#define NULL (void*)0 //added for serial port hw
extern long __bss_start;
extern long __bss_end;

void clear_bss();


void kernel_main() {
	
	clear_bss();
	
	esp_printf(putc, "The memory location is %x", kernel_main);

	//led_init();	
	/*while(1){
		/*
		led_on();
		delay(300);
		led_off();
		delay(300);
		*/				
	//}*/  
  
}
/*
struct list_element c = {NULL, 0};
struct list_element b = {&c, 0};
struct list_element a = {&b, 0};
struct list_element *head = &a;
*/

//hw1

void clear_bss(){
	char *begin = (char *) &__bss_start; //equivalent to &arr[0];
	char *end = (char *) &__bss_end; //equivalent to &arr[size] 
	for (; begin < end; begin++){ //set initial to beginning address of bss, while the address < end address, increment address
		*begin = 0; //dereference address and set value to 0
	
	}
}


//in class activity

/*unsigned long get_timer_count(){
		unsigned long *timer_count_register = 0xfe003004;
		return *timer_count_register;
}
* /


/*
unsigned int el; 
asm("mrs %0, CurrentEL"
	: "=r" (el)
	:
	:);
*/

