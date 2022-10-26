#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <keyboard_driver.h>

void write(int fd, char*buffer, size_t count);
int read(int fd, char * buffer, size_t count);

#endif