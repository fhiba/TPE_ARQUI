#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <stddef.h>

int64_t write(int fd, char * buffer, size_t count);

#endif