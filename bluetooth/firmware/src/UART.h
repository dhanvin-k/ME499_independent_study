#ifndef _UART_H    /* Guard against multiple inclusion */
#define _UART_H

#include <xc.h>                     // processor SFR definitions
#include <sys/attribs.h>            // __ISR macro

//#define NU32_LED1 LATFbits.LATF0    // LED1 on the NU32 board
//#define NU32_LED2 LATFbits.LATF1    // LED2 on the NU32 board
//#define NU32_USER PORTDbits.RD7     // USER button on the NU32 board
#define PIC32_SYS_FREQ 48000000ul    // 80 million Hz

void UART_Startup(void);
void ReadUART1(char * string, int maxLength);
void WriteUART1(const char * string);

#endif 