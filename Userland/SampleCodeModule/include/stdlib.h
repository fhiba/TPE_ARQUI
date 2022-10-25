#ifndef STDLIB_H
#define STDLIB_H

#include <syscallslib.h>

int strcpy(char * to, char *from);
int strcmp(char*str1,char*str2);
int scanf(char * buffer);
void printf(char * string);
void putchar(char c);
int strlen(char * string);
void clear(void);

#endif