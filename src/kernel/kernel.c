#include "kernel.h"
#include "drivers/vga/vga.h"
#include "drivers/io/io.h"
#include "drivers/keyboard/keyboard.h"

size_t strlen(const char* str) {
	size_t len = 0;
	while(str[len]) {
		len++;
	}
	
	return len;
	
}

void kernel_main() {
	terminal_initialize();
	for(int i = 0; i <= 115; i++) {
		imprimir_texto("=");
	}
	imprimir_texto("CalcOS");
	for(int x = 0; x <= 115; x++) {
		imprimir_texto("=");
	}
	imprimir_texto("==\n\nCalculadora creada por Huguini79, presiona ALT para volver a este menu, eso deberias usarlo si estas en la seccion de suma, de resta, de multiplicacion o de division y quieres ir a la otra seccion\n\n\n\n");
	imprimir_texto("Introduce la opcion de calculo: suma, resta, multiplicacion, division: \n\n> ");
	outb(0x60, 0xff);
	detectar_teclado();
}
