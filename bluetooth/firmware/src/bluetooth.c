#include<bluetooth.h>
#include<xc.h>
#include<ili9341.h>

void bluetoothInitialize() {
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;
    
    RPB3Rbits.RPB3R = 0b0001;
    U1RXRbits.U1RXR = 0b0100;
    
    U1MODEbits.BRGH = 1;
    U1BRG = 150; // ?
    
    U1TXREG = 1<<8;
    U1RXREG = 1<<8;
    
    U1STAbits.URXEN = 1;
    U1STAbits.UTXEN = 1;
    
    IEC1bits.U1TXIE = 1;
    IEC1bits.U1RXIE = 1;
    
    HC_08_sendString("Bluetooth Ready");
    broadcastBluetooth();
}
char message[20];
void HC_08_sendChar(char byte)   {
    U1TXREG = byte;
    while(!IFS1bits.U1TXIF);
    while(!U1STAbits.TRMT);
}

void HC_08_sendString(char* string) {
    while(*string) {
        HC_08_sendChar(*string++);
    }
}

void broadcastBluetooth() {
    U1TXREG = 13;
    long int curr_time = _CP0_GET_COUNT();
    // delay
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT()< 12000000) {
      ;
    }
    _CP0_SET_COUNT(curr_time + 12000000);
}

