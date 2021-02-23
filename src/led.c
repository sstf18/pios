/*led.c*/
#include "led.h"

unsigned int *gpfsel4 = 0xFE200010;
unsigned int *gpset1 = 0xFE200020;
unsigned int *gpclr1 = 0xFE20002c;


//initializing the GPIO 42 bits 8:6
//gpfsel4(bit:31:30,29:27...8:6,5:3,2,0)
//...000,001,000,000(set 1 << 6)
//FSEL 49-48-47-46-45-44-43-42-41-40

void led_init(){
	unsigned int mask_number = 0xFFFFFE3F;
	*gpfsel4 = *gpfsel4 & mask_number;
	*gpfsel4 = *gpfsel4 | (1 << 6);
	return;
}

//turning the ACT LED On
//GPSET0(0-31);GPSET1(31-63)
//32-33-34-35-36-37-38-39-40-41-42
// (set the position 10 to 1)

void led_on(){
	*gpset1 = (1 << 10);
}

//turning the ACT LED Off
//GPCLR0(0-31); GPCLR1(32-63)

void led_off(){
	*gpclr1 = (1 << 10);
}

void delay(unsigned int d){
	unsigned int i,j;
	for (i = 0; i < 0x7f; i++){
		for (j = 0; i<d; j++){
			asm("nop");
		}
	}

}
