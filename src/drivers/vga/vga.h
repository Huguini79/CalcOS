#ifndef VGA_H
#define VGA_H

#include <stddef.h>
#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

uint16_t terminal_make_char(char c, char colour);
void terminal_putchar(int x, int y, char c, char colour);
void terminal_writechar(char c, char colour);
void terminal_initialize();
void imprimir_texto(const char* str);
void limpiar_pantalla();

#endif
