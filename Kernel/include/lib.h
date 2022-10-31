#ifndef LIB_H
#define LIB_H

#include <stdint.h>
void * memset(void * destination, int32_t character, uint64_t length);
void * memcpy(void * destination, const void * source, uint64_t length);
void sleep(long ms);
char *cpuVendor(char *result);
char rtcGet(char value);
void saveRegisters(uint64_t registerValues[17]);
uint64_t getDir(uint64_t dir);
#endif