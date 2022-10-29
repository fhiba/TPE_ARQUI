#ifndef _OURLIB_
#define _OURLIB_


typedef struct{
    int rax;
    int rbx;
    int rcx;
    int rdx;
    int rbp;
    int rdi;
    int rsi;
    int r8;
    int r9;
    int r10;
    int r11;
    int r12;
    int r13;
    int r14;
    int r15;
} registersT;

int strcpy(char * to, char *from);
int strcmp(char*str1,char*str2);
int scanf(char * buffer);
void printf(char * string);
void putchar(char c);
int strlen(char * string);
void clear(void);
int atoi(char * str);

#endif