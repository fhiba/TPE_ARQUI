#include <tron.h>

#define AMOUNT 1
#define MAX_LENGTH 1000
#define P1_COLOR 0x00ffff
#define P2_COLOR 0xffff00



typedef struct rect
{
    int x;
    int y;
    int width;
    int height;
}rect;


typedef struct playerPos{
    unsigned int x;
    unsigned int y;
}playerPos;

void getDirs();
void initPos();
void updatePos();
int checkWinner();
void refresh();
int checkCollision(playerPos, playerPos);


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

char actions[3];
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
        sys_read(1, actions, 3);
        for(action_idx = 0; action_idx < 3 && winner == 0 && quit == 0; action_idx++) {
            if(actions[action_idx] != 0x7F) { 
                if(player_Length < MAX_LENGTH){
                    player_Length++;
                }
                updatePos();

                winner = checkWinner();
                refresh();
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
    //sys_beep();
    sys_sleep(2000);
    sys_clear();
}

void updatePos() {
    p1_lastDir = p1_Dir;
    p2_lastDir = p2_Dir;
    getDirs();
    int i = 1;
    for(; i < player_Length ; i++) {
        player1[i].x = player1[i - 1].x;
        player1[i].y = player1[i - 1].y;
        player2[i].x = player2[i - 1].x;
        player2[i].y = player2[i - 1].y;
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

    p1_Dir = RIGHT;
    p2_Dir = LEFT;
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
        // sys_recto(player1[i].x - AMOUNT, player1[i].y - AMOUNT,P1_COLOR , AMOUNT, AMOUNT);
        // sys_recto(player2[i].x - AMOUNT, player2[i].y - AMOUNT,P2_COLOR , AMOUNT, AMOUNT);
        sys_recto(player1[i].x, player1[i].y, P1_COLOR, AMOUNT, AMOUNT);
        sys_recto(player2[i].x, player2[i].y, P2_COLOR, AMOUNT, AMOUNT);
        i++;
    }
}

int checkWinner() {

    if(player1[0].x > 1024 || player1[0].x < 0 || player1[0].y > 768 || player1[0].y < 0)
        return 2;

    if(player2[0].x > 1024 || player2[0].x < 0 || player2[0].y > 768 || player2[0].y < 0)
        return 1;


    for(int i = 0; i < player_Length; i++) {
        if(checkCollision(player1[0], player2[i]) != 0)
            return 2;

        if(checkCollision(player2[0], player1[i]) != 0)
            return 1;
        // if(i > AMOUNT * AMOUNT * 2 && checkCollision(player1[0], player1[i]) != 0)
        //     return 2;
    }



    

    // if(i > AMOUNT && checkCollision(player2[0], player2[i]) != 0)
    //     return 2;
    // if(checkCollision(player1[0]))
    //     return 2;

    // if(checkCollision(player2[0]))
    //     return 1;

    return 0;
}


int checkCollision(playerPos head, playerPos outer_body) {
    // playerPos head_top;
    // head_top.x = head.x - AMOUNT;
    // head_top.x = head.y - AMOUNT;
    
    // playerPos head_bottom; 
    // head_bottom.x = head.x + AMOUNT;
    // head_bottom.x = head.y + AMOUNT;

    // playerPos body_top;
    // body_top.x = outer_body.x - AMOUNT;
    // body_top.x = outer_body.y - AMOUNT;
    
    
    // playerPos body_bottom;
    // body_bottom.x = outer_body.x + AMOUNT;
    // body_bottom.x = outer_body.y + AMOUNT;
    // long dist_x = (head.x - outer_body.x);
    // long dist_y = (head.y - outer_body.y);   
    // long dist_x2 = dist_x * dist_x;
    // long dist_y2 = dist_y * dist_y;
    // if(dist_x2 + dist_y2 < AMOUNT * AMOUNT)
    if(isBlackPixel(head.x, head,y) == 0)
        return 1;
    //if(head.x == outer_body.x && head.y == outer_body.y)
      //  return 1;


    // for (int i = - AMOUNT; i <= AMOUNT; i++) {
    //     for(int j = - AMOUNT; j <= AMOUNT; j++) {
    //         if(head.x + i >= 0 && head.x + i <= 1024 && head.y + j >= 0 && head.y + j <= 768) {
    //             if (sys_isBlackPixel(head.x + i, head.y + j) == 0)
    //                 return 1;
    //         }
    //     }
    // }
    return 0;
}


int valueInRange(int value, int min, int max)
{ return (value >= min) && (value <= max)? 1:0; }

int rectOverlap(playerPos head, playerPos body) {
    rect A;
    A.x = head.x - AMOUNT;
    A.x = head.y - AMOUNT;
    A.height = AMOUNT * 2;
    A.width = AMOUNT * 2;
    
    rect B;
    B.x = body.x - AMOUNT;
    B.x = body.y - AMOUNT;
    B.height = AMOUNT * 2;
    B.width = AMOUNT * 2;

    int xOverlap = valueInRange(A.x, B.x, B.x + B.width) +
                    valueInRange(B.x, A.x, A.x + A.width);

    int yOverlap = valueInRange(A.y, B.y, B.y - B.height) +
                    valueInRange(B.y, A.y, A.y - A.height);

    return (xOverlap > 0) && (yOverlap>0);
}