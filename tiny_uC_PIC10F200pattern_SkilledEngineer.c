/*
 * File:   tiny_uC_PIC10F200.c
 * Author: Skilled Engineer 
 * Subscribe/ Follow at YouTube : @SkilledEngineer || Facebook/Instagram : /SkilledEngineerOfficial
 */


#include <xc.h>

#define _XTAL_FREQ 4000000

#pragma config WDTE = ON        // Watchdog Timer (WDT enabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable (GP3/MCLR pin function  is MCLR)

#define redLED GP0
#define greenLED GP1
#define blueLED GP2

#define pushButton GP3

char i;
char loopcount=20;
char timedelay=10;

void main(void) {
    
TRISGPIO = 0b00001000;
OPTION = 0b11010000;

 GPIO = 0b00000000;
 
 while(!pushButton);
 
 while(1)
 {
 greenLED = 0;
 blueLED = 0;
 for(i=0;i<loopcount;i++)
 {
     redLED ^= 1;
     __delay_ms(timedelay);
 }
//---------------------------------
 __delay_ms(50);
 
 redLED = 0;
 blueLED = 0;
 for(i=0;i<loopcount;i++)
 {
     greenLED ^= 1;
     __delay_ms(timedelay);
 }
 //---------------------------------
 __delay_ms(50);
 
 greenLED = 0;
 redLED = 0;
 for(i=0;i<loopcount;i++)
 {
     blueLED ^= 1;
     __delay_ms(timedelay);
 }
 
 } 
    return;
}
