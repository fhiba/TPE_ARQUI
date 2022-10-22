extern unsigned char getKey();
#include <keyboard_driver.h>

unsigned char key = 0;
extern unsigned char last;

unsigned char readKey() {
    unsigned char aux = key;
    key = 0;
    return aux;
}

void keyboard_handler() {
    key = charHexMap[getKey()];
    if(key != 0)
        last = key;
}