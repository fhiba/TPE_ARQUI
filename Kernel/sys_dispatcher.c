#include <syscalls.h>
#include <stddef.h>
#include <naiveConsole.h>


static int sys_num;

void sys_setter(int num){
    sys_num = num;
}

int64_t sys_dispatcher(int arg0,int arg1, int arg2){
    switch(sys_num){
        case 2:
            return write(arg0,(char*)arg1,(size_t)arg2);
        case 3:
            idle(arg0);
            return 0;
        default:
            return -1;
    }
    return -1;
}