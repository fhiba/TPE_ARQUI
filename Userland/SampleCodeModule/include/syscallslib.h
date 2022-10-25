#ifndef _syscallslib_
#define _syscallslib_

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

int sys_read(int fd,char * buffer, size_t count);
void sys_write(int fd, const char * buffer, size_t count);
void sys_printMem(uint64_t, unsigned char *);
void sys_clear();
char sys_date(char value);
void sys_sleep(int secs);
void sys_setScreen(int mode);
void sys_inforeg(registersStruct*);
void sys_snapshotRegs(void);

#endif