extern unsigned char getKey();
#include <keyboard_driver.h>

unsigned char key = 0;
// unsigned char flag = 0;
unsigned char last;

unsigned char readKey() {
    unsigned char aux = key;
    key = 0;
    return aux;
}

void keyboard_handler() {
    // flag = 1;
    key = charHexMap[getKey()];
    if(key != 0)
        last = key;
}