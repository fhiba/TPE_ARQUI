#include <programs.h>
#include <syscallslib.h>
#include <shell.h>


void shell(void){
    char buffer[100] = {0};
    int idx = 0;
    while(1){
        printFirst("$ ");
        do{
            sys_read(1, buffer + idx, 1);
            if(buffer[idx] != 0x7F){
                sys_write(1, buffer + idx, 1);
                idx++;
            }
            else if (idx > 0) {
                sys_write(1, buffer + idx, 1);
                idx--;
            }
        }while(buffer[idx-1] != '\n');
        buffer[idx-1] = 0;         
        getProgram(buffer);
        idx = 0;
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
    else if(strcmp(buffer,"INFOREG"))
        infoRegs();
    else if(strcmp(buffer, "DIVZERO"))
        sys_divzero();
    else if(strcmp(buffer, "OPCODE"))
        sys_opcode();
    else if(strcmp(buffer,"TEST"))
        test();
    else
        printerr("Invalid Command\n");
}