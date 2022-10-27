#include <mylib.h>

int strlen(char * str){
    int i = 0;
    while(str[i] != 0){
        i++;
    }
    return i;
}

void printf(char * buffer){
    sys_write(1,buffer,strlen(buffer));
}

void idle(long ms){
    sys_idle(ms);
}