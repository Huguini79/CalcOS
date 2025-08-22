#include "calculadora.h"
#include "kernel/kernel.h"
#include "drivers/vga/vga.h"
#include "drivers/keyboard/keyboard.h"

void sumar() {
for(int i = 0; i <= 115; i++) {
		imprimir_texto("=");
	}
	imprimir_texto("Sumar");
	for(int x = 0; x <= 115; x++) {
		imprimir_texto("=");
	}
	imprimir_texto("===\n\nIntroduce un numero, por ejemplo si quieres sumar 5 + 5, debes poner 55, y si quieres sumar 1 + 1 11, y si quieres sumar 1 + 4 + 6, debes poner 146: \n\n> ");
}

void restar() {
for(int i = 0; i <= 115; i++) {
		imprimir_texto("=");
	}
	imprimir_texto("Restar");
	for(int x = 0; x <= 115; x++) {
		imprimir_texto("=");
	}
	imprimir_texto("==\n\nIntroduce un numero, por ejemplo si quieres restar 5 - 5, debes poner 55, y si quieres restar 1 - 1 11, y si quieres restar 1 - 4 - 6, debes poner 146: \n\n> ");
}

void multiplicar() {
for(int i = 0; i <= 115; i++) {
		imprimir_texto("=");
	}
	imprimir_texto("Multiplicar");
	for(int x = 0; x <= 110; x++) {
		imprimir_texto("=");
	}
	imprimir_texto("==\n\nIntroduce un numero, por ejemplo si quieres multiplicar 5 * 5, debes poner 55, y si quieres multiplicar 1 * 1 11, y si quieres multiplicar 1 * 4 * 6, debes poner 146: \n\n> ");
}

void dividir() {
for(int i = 0; i <= 115; i++) {
		imprimir_texto("=");
	}
	imprimir_texto("Dividir");
	for(int x = 0; x <= 115; x++) {
		imprimir_texto("=");
	}
	imprimir_texto("=\n\nIntroduce un numero, por ejemplo si quieres dividir 5 / 5, debes poner 55, y si quieres dividir 1 / 1 11, y si quieres dividir 1 / 4 / 6, debes poner 146: \n\n> ");
}
