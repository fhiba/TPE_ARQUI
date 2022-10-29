#include <programs.h>
#include <shell.h>


void shell(void){
    char buffer[100];
    while(1){
        printFirst("$ ");
        int length = scanf(buffer);
        buffer[length - 1] = 0;
        getProgram(buffer);
    }
}

void getProgram(char * buffer){
    if(strcmp(buffer,"HELP"))
        help();
    else if(strcmp(buffer,"DATE"))
        date();
    else if(strcmp(buffer,"CLEAR"))
        clearProg();
    else if(strcmp(buffer,"RESIZE"))
        resize();
    else if(strcmp(buffer,"EXIT"))
        exitShell();
    else if(strcmp(buffer,"TRON"))
        tron();
    else if(strcmp(buffer,"TEST"))
        test();
    else
        printerr("Invalid Command\n");
}