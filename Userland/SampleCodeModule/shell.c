#include <ourlib.h>
#include <programs.h>
#include <shell.h>


void shell(void){
    char buffer[100];
    while(1){
        printf("$ ");
        int length = scanf(buffer);
        buffer[length - 1] = 0;
        getProgram(buffer);
    }
}

function getProgram(char * buffer){
    function ret;
    if(strcmp(buffer,"date"))
        ret = &help;
    else if(strcmp(buffer,"clear"))
        ret = &clear;
    return ret;
}