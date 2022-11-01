#include <syscalls.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>

#define STDIN 1
#define RETVALUE -1




void write(int fd, char*buffer, size_t count){
    int color = 0;
    for(int i =0;i<count;i++){
        if(buffer[i] == '\n'){
            ncNewline();
        } else if (buffer[i] == 0x7F) {
            deleteChar();
        } else {
            switch(fd){
            case 1:
                color = BLANCO;
                break;
            case 2:
                color = ROJO;
                break;
            case 3:
                color = VERDE;
                break;
            case 4:
                color = CELESTE;
                break;
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
        while(k < count && key == 0){
            _hlt();
            key = readKey();
            if(key == '=') {
                takeSnapshot();
            }
                
            if(key != 0)
                buffer[k++] = key;
        }
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
            write(4,registerNames[i],3);
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