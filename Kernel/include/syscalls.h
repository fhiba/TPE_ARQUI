#ifndef SYSCALL_H_
#define SYSCALL_H_
#include <stddef.h>
#include <stdint.h>

void write(int fd, char* buffer, size_t count);
int read(int fd, char * buffer, size_t count);
void inforegs();
void takeSnapshot();
int64_t date(char value);
#endif