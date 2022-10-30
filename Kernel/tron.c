#include <naiveConsole.h>
#include <keyboard_driver.h>

void tronRun(){
    ncClear();
    pos p1,p2;
    p1.x = getWidth()/4;
    p1.y = getHeight()/2;
    p2.x = 3*getWidth()/4;
    p2.y = getHeight()/2;
    char aux = 0,last = 0;
    while(compare(p1,p2)==0){
        while(last == aux){
            aux = charHexMap[readKey()];
        }
        switch (aux)
        {
        case 'W':
            p1.y+=2;
            fillRect((unsigned char *)(getScreen() + p1.x + p1.y),ROJO,2,2);
            break;
        case 'S':
            p1.y-=2;
            fillRect((unsigned char *)(getScreen() + p1.x + p1.y),ROJO,2,2);
            break;
        case 'A':
            p1.x-=2;
            fillRect((unsigned char *)(getScreen() + p1.x + p1.y),ROJO,2,2);            
            break;
        case 'D':
            p1.x+=2;
            fillRect((unsigned char *)(getScreen() + p1.x + p1.y),ROJO,2,2);            
            break;
        case 'I':
            p2.y+=2;
            fillRect((unsigned char *)(getScreen() + p2.x + p2.y),CELESTE,2,2);            
            break;
        case 'K':
            p2.y-=2;
            fillRect((unsigned char *)(getScreen() + p2.x + p2.y),CELESTE,2,2);            
            break;
        case 'L':
            p2.x+=2;
            fillRect((unsigned char *)(getScreen() + p2.x + p2.y),CELESTE,2,2);            
            break;
        case 'J':
            p2.x-=2;
            fillRect((unsigned char *)(getScreen() + p2.x + p2.y),CELESTE,2,2);            
            break;
        default:
            break;
        }
        last = aux;
    }
}