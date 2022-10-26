#ifndef SHELL_H
#define SHELL_H

#include <programs.h>

typedef char (*function)(void);



void shell(void);
function getProgram(char * name);

#endif