#include <tron.h>

#define AMOUNT 2
#define MAX_LENGTH 500
#define P1_COLOR 0x00ffff
#define P2_COLOR 0xffff00

void getDirs();
void initPos();
void updatePos();
int checkWinner();
void refresh();
int checkCollision();

typedef struct playerPos{
    int x;
    int y;
}playerPos;

playerPos player2[MAX_LENGTH];
playerPos player1[MAX_LENGTH];

typedef enum directions{
    UP,
    DOWN,
    LEFT,
    RIGHT
}directions;

directions p1_Dir;
directions p2_Dir; 
directions p1_lastDir;
directions p2_lastDir; 
int player_Length = 0;

char actions[10] = {-1};
int action_idx = 0;

void tronRun(){
    sys_clear();
    
    initPos(); //setea los bordes de la cancha (NO DEFINIDO TODAVIA)
    int winner = 0; //luego de mover va a una funcion que chequea por colision, si hubo unca carga 1 si gano 1 o 2 si gano 2.
    int quit = 0;
    do{
        //sys_read(1,&c,1);
        /*
            opt1- last de cada uno
            opt2- 
            
            updatePos();
            refresh();
            winner();
        */
        sys_read(1, actions, 10);
        for(action_idx = 0; action_idx < 10 || winner == 0; action_idx++) {
            if(quit == 0) { 
                player_Length++;
                updatePos();
                refresh();
                winner = checkWinner();
                sys_sleep(30);
            } else{
                quit = 1;
            }
        }
    } while(quit == 0 && winner == 0);
    
    sys_clear();
    
    if(winner != 0) {
        sys_write(1, "Player ", 7);
        sys_write(1, winner == 1? "1 ":"2 ", 2);
        sys_write(1, "won.", 4);
    }
    
    //
}

void updatePos() {
    p1_lastDir = p1_Dir;
    p2_lastDir = p2_Dir;
    getDirs();
    int i = 1;
    for(; i < player_Length ; i++) {
        player1[i] = player1[i - 1];
        player2[i] = player2[i - 1];
    }
    switch(p1_Dir) {
        case UP:
            if(p1_lastDir != DOWN)
                player1[0].y -= AMOUNT;
            break;
        case DOWN:
            if(p1_lastDir != UP)
                player1[0].y += AMOUNT;
            break;
        case LEFT:
            if(p1_lastDir != RIGHT)
                player1[0].x -= AMOUNT;
            break;
        case RIGHT:
            if(p1_lastDir != LEFT)
                player1[0].x += AMOUNT;
            break;
    }
    switch(p2_Dir) {
        case UP:
            if(p2_lastDir != DOWN)
                player2[0].y -= AMOUNT;
            break;
        case DOWN:
            if(p2_lastDir != UP)
                player2[0].y += AMOUNT;
            break;
        case LEFT:
            if(p2_lastDir != RIGHT)
                player2[0].x -= AMOUNT;
            break;
        case RIGHT:
            if(p2_lastDir != LEFT)
                player2[0].x += AMOUNT;
            break;
    }
}


void initPos() {
    player1[0].x = 1024/4;
    player1[0].y = 768/2;

    player2[0].x = 3*1024/4;
    player2[0].y = 768/2;

    p1_Dir = UP;
    p2_Dir = DOWN;
}


void getDirs() {
    
        switch(actions[action_idx]){
            case 'W':
                if(p1_lastDir != DOWN)
                    p1_Dir = UP;
                break;
            case 'A':
                if(p1_lastDir != RIGHT)
                   p1_Dir = LEFT;
                break;
            case 'S':
                if(p1_lastDir != UP)
                   p1_Dir = DOWN;
                break;
            case 'D':
                if(p1_lastDir != LEFT)
                   p1_Dir = RIGHT;
                break;
            case 'I':
                if(p2_lastDir != DOWN)
                   p2_Dir = UP;
                break;
            case 'J':
                if(p2_lastDir != RIGHT)
                   p2_Dir = LEFT;
                break;
            case 'K':
                if(p2_lastDir != UP)
                   p2_Dir = DOWN;
                break;
            case 'L':
                if(p2_lastDir != LEFT)
                   p2_Dir = RIGHT;
                break;
            default:
                break;
        }
}


void refresh() {
    int i = 0;
    while (i < player_Length) {
        sys_recto(player1[i].x - AMOUNT, player1[i].y - AMOUNT,P1_COLOR , AMOUNT, AMOUNT);
        sys_recto(player2[i].x - AMOUNT, player2[i].y - AMOUNT,P2_COLOR , AMOUNT, AMOUNT);
        i++;
    }
}

int checkWinner() {
    for(int i = 0; i < player_Length; i++) {
        if(checkCollision(player1[0], player2[i]))
            return 2;
        if(checkCollision(player2[0], player1[i]))
            return 1;
    }
    return 0;
}


int checkCollision(playerPos head, playerPos outer_body) {
    playerPos head_left;
    head_left.x = head.x - AMOUNT;
    head_left.x = head.y - AMOUNT;
    
    playerPos head_right; 
    head_right.x = head.x + AMOUNT;
    head_right.x = head.y + AMOUNT;

    playerPos body_left;
    body_left.x = outer_body.x - AMOUNT;
    body_left.x = outer_body.y - AMOUNT;
    
    
    playerPos body_right;
    body_right.x = outer_body.x + AMOUNT;
    body_right.x = outer_body.y + AMOUNT;

    if (head_left.x < body_right.x && head_right.x > body_left.x && head_left.y > body_right.y && head_right.y < body_left.y)
        return 1;
    return 0;
}
