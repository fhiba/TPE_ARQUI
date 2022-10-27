#ifndef _syscallslib_
#define _syscallslib_

#include <stddef.h>

void sys_write(int arg0,char * arg1,size_t arg2);
void sys_idle(long ms);

#endif