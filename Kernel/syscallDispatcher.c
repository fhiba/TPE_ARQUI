#include <stddef.h>
#include <syscalls.h>
#include "./include/time.h"

static int num_syscall;
extern void divzero();
extern void opcode();

void set_syscall(int num){
    num_syscall = num;
}

int sys_dispatcher(int arg0, int arg1, int arg2, int arg3){
    switch(num_syscall){
        case 1:
            read(arg0,(char*)arg1,(size_t)arg2);
            break;
        case 2:
            write(arg0,(char*)arg1,(size_t)arg2);
            break;
        case 3:
            clear();
            break;
        case 4:
            takeSnapshot();
            break;
        case 5:
            inforegs();
            break;
        case 7:
            tsleep((long)arg0);
            break;
        case 6:
            mydate(arg0);
            break;
        case 9:
            resize(arg0);
            break;
        case 14:
            divzero();
            break;
        case 15:
            opcode();
            break;
        case 16:
            fillRect((unsigned char *)arg0,arg1,arg2,arg3);
        default:
            return -1;
    }
    return -1;
}