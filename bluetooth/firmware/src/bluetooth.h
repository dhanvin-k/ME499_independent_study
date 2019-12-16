#ifndef _BLUETOOTH_H    /* Guard against multiple inclusion */
#define _BLUETOOTH_H

void bluetoothInitialize();
void HC_08_sendChar(char byte);
void HC_08_sendString(char* string);
void broadcastBluetooth();

#endif 