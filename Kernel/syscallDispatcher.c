#include <stddef.h>
#include <syscalls.h>

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
        default:
            return -1;
    }
    return -1;
}