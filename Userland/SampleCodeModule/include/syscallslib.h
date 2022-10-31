#ifndef _syscallslib_
#define _syscallslib_

#include <stddef.h>
#include <ourlib.h>
#include <stdint.h>

int sys_read(int fd,char * buffer, size_t count);
void sys_write(int fd, const char * buffer, size_t count);
void sys_printMem(uint64_t dir);
void sys_clear();
char sys_date(char value);
void sys_sleep(int secs);
void sys_setScreen(int mode);
void sys_infoRegs();
void sys_snapshotRegs(void);
void sys_resize(int num);
void sys_tron();

#endif