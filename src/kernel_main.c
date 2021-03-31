
#include "list.h"
#include "led.h"
#include "rprintf.h"
#include "serial.h"
#include "page.h"
//#include "mmu.h"
#include "gpio.h"
#include "fat.h"
#include "sd.h"
#include "fat.h"

int global;
#define NULL (void*)0 //added for serial port hw
extern int __bss_start;
extern int __bss_end;
extern struct ppage* free_list; 
void clear_bss();

void kernel_main() {
	
	struct file fat_test;
	
	sd_init();
	fatInit();
	fatOpen(&fat_test, "TEST");
	fatRead(&fat_test, "TESTFILE", 32);
	while(1){
		
	}
	//mmu_on();
	//clear_bss();
	
	/*
	init_pfa_list();
	struct ppage* test = free_list ;
	esp_printf(putc, "physical addr 0: %x \n", test->physical_addr);
	esp_printf(putc, "physical addr 1: %x \n", test->next->physical_addr);
	esp_printf(putc, "physical addr 2: %x \n", test->next->next->physical_addr);
	esp_printf(putc, "physical addr 3: %x \n", test->next->next->next->physical_addr);	
	
	test = allocate_physical_pages(2);
	esp_printf(putc, "allocated pages list : %x \n", test);
	esp_printf(putc, "allocated addr list : %x \n", test->physical_addr);
	esp_printf(putc, "allocated addr list : %x \n", test->next->physical_addr);		
	
	free_physical_pages(test);
	test = free_list->next;
	esp_printf(putc,"after free page: %x \n", test);
	esp_printf(putc,"after free addr: %x \n", test->physical_addr);
	esp_printf(putc,"after free addr: %x \n", test->next->physical_addr);
	*/
	
			
	//esp_printf(putc, "The memory location is %x", kernel_main);

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

