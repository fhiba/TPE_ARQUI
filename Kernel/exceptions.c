#include <stdlib.h>
#include <syscalls.h>

#define ZERO_EXCEPTION_ID 0
#define INVALID_OPCODE_EXCEPTION_ID 6

static void zero_division();
static void invalid_opcode();

void exceptionDispatcher(int exception) {
	if (exception == ZERO_EXCEPTION_ID)
		zero_division();
	if(exception == INVALID_OPCODE_EXCEPTION_ID)
		invalid_opcode();
}

static void zero_division() {
	write(1, "Err: You may not divide by zero.\n", 33);
}

static void invalid_opcode() {
	write(1, "Err: Invalid Opcode\n", 20);
	inforegs();
}