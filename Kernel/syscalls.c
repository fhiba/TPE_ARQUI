#include <syscalls.h>
#include <naiveConsole.h>
#include <time.h>
#include <lib.h>

int64_t write(int fd, char * buffer, size_t count){
    for(int i = 0; i<count;i++){
        drawChar(buffer[i],0xffffff,0x000000);
    }
    ncNewline();
}

void idle(long ms){
    sleep(ms);
}