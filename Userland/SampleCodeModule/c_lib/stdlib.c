#include <syscallslib.h>

#define STDIN 1

int strlen(char * string){
    int i = 0;
    while(string[i]!=0){
        i++;
    }
    return i;
}

void putchar(char c){
    sys_write(STDIN,&c,1);
}

void printf(char * string){
    sys_write(STDIN,string,strlen(string));
}