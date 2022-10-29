#include <syscalls.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>
#include <tron.h>

#define STDIN 1
#define RETVALUE -1

void write(int fd, char*buffer, size_t count){
    int color = 0;
    for(int i =0;i<count;i++){
        if(buffer[i] == '\n'){
            ncNewline();
        }
        else{
            if(fd == 1)
                color = BLANCO;
            else if(fd == 2){
                color = ROJO;
            }
            else if(fd == 3){
                color = VERDE;
            }
            drawChar(buffer[i],color,NEGRO);
        }
    }
}

int read(int fd, char * buffer, size_t count){
    if(fd == STDIN)
    {
        int k = 0;
        unsigned char key = 0;
        while(key != '\n' && k < count){
            _hlt();
            key = readKey();
            switch(key){
                case 0:
                    break;
                case 0xF0:
                    if(k > 0){
                        deleteChar(); //IMPLEMENTAR
                        k--;
                    }
                    break;
                case '\n':
                    break;
                default:
                {
                    drawChar(key,0xffffff,0x000000);
                    buffer[k++] = key;
                }
            }
        }
        if(key == '\n'){
            ncNewline();
        }
        buffer[k] = 0;
        return k;
    }
    return -1;
}

void clear(){
    ncClear();
}

void resize(int num){
    nResize(num);
}

void mydate(char value){
    rtcGet(value);
}