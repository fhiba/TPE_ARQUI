#include <programs.h>
#include <ourlib.h>
#include <syscallslib.h>

void help(){
    printf("Available Commands: \n-date\n-clear\n-help\n");
}

void clearProg(){
    clear();
}

void resize(){
    printf("Choose a multiplier to resize the font!\n");
    char buffer[1];
    scanf(buffer);
    int aux = atoi(buffer);
    sys_resize(aux);
}

void exitShell(){
    printf("exit?\n");
}


char getDateValues(int value){
    sys_date(value);
}

void date(){
    int values[5] = {7,8,9,4,2};
    char buffer[3];
    for(int i = 0; i < 5;i++){
        char num = getDateValues(values[i]);
        if(num < 0xA){

        }
    }
}


void tron(){
    clear();
    printf("Welcome to tron!");
}
void infoRegs(){
    sys_infoRegs();
}