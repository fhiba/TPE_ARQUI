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

void clear(void){
    sys_clear();
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

int strcmp(char*str1,char*str2){ //devuelve 0 si son distintos y 1 si son iguales
    int pos = 0;
    while(str1[pos]&&str2[pos]){
        if(str1[pos]!=str2[pos])
            return 0;
        pos++;
    }
    if(str1[pos]||str2[pos])
        return 0;
    return 1;
}

int strcpy(char * to, char *from){
    int i;
    for(i =0; from[i] != 0; i++){
        to[i] = from[i];
    }
    to[i] = 0;
    return i;
}

int atoi(char * str){
    int res = 0;
    for(int i = 0; str[i] != '\0';i++){
        res = res*10+str[i]-'0';
    }
    return res;
}