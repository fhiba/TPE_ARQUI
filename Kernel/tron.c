#include <naiveConsole.h>
#include <keyboard_driver.h>




void tronRun(){
    ncClear();
    // unsigned char * player1 = 30;
    // unsigned char * player2 = 50;
    // pos p1,p2;
    // p1.x = 0;
    // p1.y = 0;
    // p2.x = 0;
    // p2.y = 0;
    // p1.x = getWidth()/4;
    // p1.y = getHeight()/2;
    // p2.x = 3*getWidth()/4;
    // p2.y = getHeight()/2;
    // char aux = 0,last = 0;
    unsigned char c;
    
    while(1){
        c = readKey();
        //if(c != 0)
            drawChar(c + 'a', BLANCO, NEGRO);    
        // switch (readKey())
        // {
        // case 'W':
        //     p1.y+=2;
        //     fillRect((player1 + p1.x + p1.y),ROJO,20,20);
        //     break;
        // case 'S':
        //     p1.y-=2;
        //     fillRect((player1 + p1.x + p1.y),ROJO,20,20);
        //     break;
        // case 'A':
        //     p1.x-=2;
        //     fillRect((player1 + p1.x + p1.y),ROJO,20,20);            
        //     break;
        // case 'D':
        //     p1.x+=2;
        //     fillRect((player1 + p1.x + p1.y),ROJO,20,20);            
        //     break;
        // case 'I':
        //     p2.y+=2;
        //     fillRect((player2 + p2.x + p2.y),CELESTE,20,20);            
        //     break;
        // case 'K':
        //     p2.y-=2;
        //     fillRect((player2 + p2.x + p2.y),CELESTE,20,20);            
        //     break;
        // case 'L':
        //     p2.x+=2;
        //     fillRect((player2 + p2.x + p2.y),CELESTE,20,20);            
        //     break;
        // case 'J':
        //     p2.x-=2;
        //     fillRect((player2 + p2.x + p2.y),CELESTE,20,20);            
        //     break;
        // default:
        //     break;
        // }
    }
}