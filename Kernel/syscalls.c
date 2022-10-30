#include <syscalls.h>
#include <naiveConsole.h>
#include <interrupts.h>
#include <lib.h>

#define STDIN 1
#define RETVALUE -1

void write(int fd, char*buffer, size_t count){
    for(int i =0;i<count;i++){
        if(buffer[i] == '\n'){
            ncNewline();
        }
        else{
            drawChar(buffer[i],BLANCO,NEGRO);
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
        write(0,"Primero debe tomar un snapshot con la tecla =",46);
        ncNewline();
    }else{
        for(int i = 0;i<17;i++){
            write(0,registerNames[i],3);
            write(0,": ",2);
            ncPrintBase(regsiterValues[i],16);
            ncNewline();
        }
    }
}

void takeSnapshot(){
    saveRegisters(regsiterValues);
    ncNewline();
    write(0,"Snapshot tomado.",17);
    ncNewline();
    write(0,"$",1);
    snapshot = 1;
}