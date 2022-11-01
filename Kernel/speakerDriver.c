#include <stddef.h>
#include <stdint.h>
//Make it go beep!

enum acordes{A=880, AS= 932, B=988, C=523, CS=554, D=587, DS=622, 
E=659, F=698, FS=740, G=784, GS=831, S=250000 , D7 = 2349};
 //Play sound using built in speaker
static void play_sound(uint32_t nFrequence) {
    uint32_t Div;
    uint8_t tmp;

        //Set the PIT to the desired frequency
    Div = 1193180 / nFrequence;
    outb(0x43, 0xb6);
    outb(0x42, (uint8_t) (Div) );
    outb(0x42, (uint8_t) (Div >> 8));

        //And play the sound using the PC speaker
    tmp = inb(0x61);
    if (tmp != (tmp | 3)) {
        outb(0x61, tmp | 3);
    }
}

//make it shutup
static void nosound() {
    uint8_t tmp = inb(0x61) & 0xFC;

    outb(0x61, tmp);
}

static void timer_wait(uint16_t ticks) {
    for (int i = 0; i < ticks; i++){
        _hlt();
    }
}

//Make a beep
void beep() {
    play_sound(1000);
    timer_wait(10);
    nosound();
        //set_PIT_2(old_frequency);
}