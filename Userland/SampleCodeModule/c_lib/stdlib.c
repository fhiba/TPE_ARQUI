#include <syscallslib.h>

#define STDIN 1
#define MAXBUFF 150


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

int scanf(char * buffer){
    return sys_read(STDIN,buffer,MAXBUFF);
}

int strcmp(char*str1,char*str2){
    int pos = 0;
    while(str1[pos]&&str2[pos]){
        if(str1[pos]!=)
    }
}