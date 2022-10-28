#ifndef SYSCALL_H_
#define SYSCALL_H_
#include <stddef.h>
void write(int fd, char* buffer, size_t count);
#endif