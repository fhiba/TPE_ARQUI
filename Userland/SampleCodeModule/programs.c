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
    return sys_date(value);
}

void test(){
    for(int i = 0; i < 6200 ; i++){
        printf("a");
        sys_sleep(20);
    }
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
    printf("Welcome to tron!\n The game will start soon! \nPlayer 1 moves with WASD and is color blue\nPlayer 2 moves with IJKL and is color red\nGOOD LUCK, HAVE FUN!\n");
    sys_sleep(2500);
    sys_tron();
}
// void infoRegs(){
//     sys_infoRegs();
// }