#include <stddef.h>
#include <syscalls.h>
#include <tron.h>
#include "./include/time.h"

static int num_syscall;

void set_syscall(int num){
    num_syscall = num;
}

int sys_dispatcher(int arg0, int arg1, int arg2){
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
        case 7:
            tsleep((long)arg0);
        case 6:
            mydate(arg0);
            break;
        case 9:
            resize(arg0);
            break;
        case 13:
            tronRun();
            break;
        default:
            return -1;
    }
    return -1;
}