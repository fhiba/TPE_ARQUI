#ifndef NAIVE_CONSOLE_H
#define NAIVE_CONSOLE_H

#include <stdint.h>
#include <stdlib.h>

void ncPrint(const char * string);
void ncPrintChar(char character);
void ncNewline();
void ncPrintDec(uint64_t value);
void ncPrintHex(uint64_t value);
void ncPrintBin(uint64_t value);
void ncPrintBase(uint64_t value, uint32_t base);
void ncClear();
void fillRect(unsigned char * vram, unsigned char r, unsigned char g, unsigned char b, unsigned char w, unsigned char h);
void drawchar(unsigned char c, int x, int y, int fgcolor, int bgcolor);
#endif