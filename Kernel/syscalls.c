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
                case '=':
                    takeSnapshot();
                    write(1,"\nSnapshot tomado.\n",18);
                    write(3,"$ ",2);
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

static char snapshot = 0;

static const char* registerNames[17] = {
    "RIP", "RAX", "RBX", "RCX", "RDX", "RSI", "RDI", "RBP", "RSP", "R8 ", "R9 ", "R10", "R11", "R12", "R13", "R14", "R15"
};

static const uint64_t regsiterValues[17] = {0};
void inforegs(){
    if(!snapshot){
        write(2,"Primero debe tomar un snapshot con la tecla =",46);
        ncNewline();
    }else{
        for(int i = 0;i<17;i++){
            write(3,registerNames[i],3);
            write(1,": ",2);
            ncPrintBase(regsiterValues[i],16);
            ncNewline();
        }
    }
}

void takeSnapshot(){
    saveRegisters(regsiterValues);
    snapshot = 1;
}