#include <programs.h>
#include <ourlib.h>
#include <syscallslib.h>
#include <tron.h>

void help(){
    printf("Available Commands: \n-DATE:\n\n| SHOWS THE CURRENT DATE AND TIME |\n\n-RESIZE\n\n| CHANGE THE SIZE OF THE FONT |\n\n-CLEAR\n\n| CLEARS THE SCREEN\n\n-TRON\n\n| PLAY A TWO-PLAYER GAME WITH A FRIEND |\n\n-DIVZERO\n\n| SEE WHAT THE DIVZERO EXCEPTION LOOKS LIKE |\n\n-OPCODE\n\n| SEE WHAT THE OPCODE EXCEPTION LOOKS LIKE |\n\n-INFOREG\n\n| AFTER TAKING A SNAPSHOT WITH = SEE WHAT VALUES THE REGISTERS HOLD! |\n");
}

void clearProg(){
    clear();
}

void resize(){
    printf("Choose a multiplier to resize the font!\n");
    char buffer[2] = {0};
    sys_read(1,buffer,1);
    printf(buffer);
    printf("\n");
    int aux = atoi(buffer);
    sys_resize(aux);
}

void exitShell(){
    printf("exit?\n");
}


char getDateValues(char value){
    return sys_date(value);
}

void test(){
    for(int i = 0; i < 6200 ; i++){
        printf("a");
        sys_sleep(20);
    }
}

void date(){
    int values[5] = {7,8,9,4,2}; //En orden: D, M, Y, H, M
    // char buffer[3] = {}; // Cada numero de la fecha no va a tener más de dos digitos, 3 contando el cero null terminated
    for (int i=0;i<5;i++){
        char num = getDateValues(values[i]);
        // cUintToBase(num,buffer,16);
        // if (num<0xA){
        //     // Si el numero es de un solo digito, lo muevo un lugar a la derecha y a la izquierda le pongo un cero
        //     char aux = buffer[0];
        //     buffer[0]='0';
        //     buffer[1]=aux;
        // }
        // buffer[2]=0; // Al string del numero le agrego un cero null terminated asi puedo usar strcpy
        sys_printBase(num, 16);
        if (i<2){
            printf("/");
        } else if (i==3){
            printf(":");
        } else {
            printf(" ");
        }
    }
    printf("UTC\n");
}

void tron(){
    clear();
    printf("Welcome to tron!\n The game will start soon! \nPlayer 1 moves with WASD and is color blue\nPlayer 2 moves IJKL and is color red\nGOOD LUCK, HAVE FUN!\n");
    sys_sleep(2500);
    tronRun();
}

void infoRegs(){
     sys_infoRegs();
}


void memPrint(){
    printf("Ingrese una direccion en hexa de 8 caracteres\n");
    printf("Ej: 12345678\n");
    char buffer[90] = {0};
    int idx = 0;
    do{
            sys_read(1, buffer + idx, 1);
            if(buffer[idx] == 0){
                
            }
            else if(buffer[idx] != 0x7F){
                sys_write(1, buffer + idx, 1);
                idx++;
            }
            else if (idx > 0) {
                sys_write(1, buffer + idx, 1);
                idx--;
            }
    }while(buffer[idx-1] != '\n');
    buffer[idx-1] = 0;    
    int ok = 1;
    uint64_t dir = stringToUint64(buffer,&ok);
    if(!ok || idx > 9){
        printf("Direccion invalida, tremendo bot\n");
        return;
    }
    unsigned char memStr[20] = {0};
    sys_printMem(dir,memStr);
    for(int i=0; i < 20; i++){
        if(i != 0 && i %5 ==0)
            putchar('\n');
        if(memStr[i] <16){
            putchar('0');
        }
        sys_printBase(memStr[i],16);

        putchar(' ');
    }
    putchar('\n');
}