#include <tron.h>

#define AMOUNT 4

typedef struct player{
    int x;
    int y;
    int color;
}player;

typedef enum directions{
    UP,
    DOWN,
    LEFT,
    RIGHT
}directions;

void tronRun(){
    sys_clear();
    directions last = 5;
    player p1;
    player p2;
    p1.x = 1024/4;
    p1.y = 768/2;
    p1.color = 0xff0000;
    p2.x = 3*1024/4;
    p2.y = 768/2;
    p2.color = 0x00ff00;
    char c = 0;
    sys_recto(400,300,0xffffff,40,40);
    sys_sleep(2500);
    // initializeGame(); //setea los bordes de la cancha (NO DEFINIDO TODAVIA)
    int winner = 0; //luego de mover va a una funcion que chequea por colision, si hubo unca carga 1 si gano 1 o 2 si gano 2.
    do{
        sys_read(1,c,1);
        switch(c){
            case 'W':
                if(last != DOWN)
                    sys_recto(p1.x, p1.y+AMOUNT,p1.color,4,4);
                break;
            case 'A':
                if(last != RIGHT)
                    sys_recto(p1.x-AMOUNT, p1.y,p1.color,4,4);
                break;
            case 'S':
                if(last != UP)
                    sys_recto(p1.x, p1.y-AMOUNT,p1.color,4,4);
                break;
            case 'D':
                if(last != LEFT)
                    sys_recto(p1.x+AMOUNT, p1.y,p1.color,4,4);
                break;
            case 'I':
                if(last != DOWN)
                    sys_recto(p2.x, p2.y+AMOUNT,p2.color,4,4);
                break;
            case 'J':
                if(last != RIGHT)
                    sys_recto(p2.x-AMOUNT, p2.y,p2.color,4,4);
                break;
            case 'K':
                if(last != UP)
                    sys_recto(p2.x, p2.y-AMOUNT,p2.color,4,4);
                break;
            case 'L':
                if(last != LEFT)
                    sys_recto(p2.x+AMOUNT, p2.y,p2.color,4,4);
                break;
        }
        winner = checkCollision();
    }
    while(c != 'Q' || winner);
    sys_sleep(2500);
}

int checkCollision(){
    return 0;
}