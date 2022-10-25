#include <naiveConsole.h>


void write(int fd, char*buffer, size_t count){
    for(int i =0;i<count;i++){
        drawChar(buffer[i],0xffffff,0x000000);
    }
}