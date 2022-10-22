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
	// Imprimir por pantalla mensaje de error.
	// Devolver a windows powershell.
}

static void invalid_opcode() {
	// Imprimir por pantalla mensaje de error.
	// Devolver a windows powershell.
}