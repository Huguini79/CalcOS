#include "keyboard.h"
#include "kernel/kernel.h"
#include "drivers/vga/vga.h"
#include "drivers/io/io.h"
#include "programs/calculadora/calculadora.h"
#include "kernel/string.h"

int pos_caracteres = 0;
int pos_numeros = 0;

bool app_calculadora = false;
char opcion[100];
char opcion_alargada[100];
int array_numeros[100];

void agregar_numero(int num) {
	array_numeros[pos_numeros++] = num;
}

void agregar_caracter(char c) {
	opcion[pos_caracteres++] = c;
	opcion[pos_caracteres] = '\0';
}

int strncmp(const char* str1, const char* str2, int n)
{
    unsigned char u1, u2;

    while(n-- > 0)
    {
        u1 = (unsigned char)*str1++;
        u2 = (unsigned char)*str2++;
        if (u1 != u2)
            return u1 - u2;
        if (u1 == '\0')
            return 0;
    }

    return 0;
}

void itoa(int num, char* buffer) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num = num / 10;
    }

    if (isNegative)
        buffer[i++] = '-';

    buffer[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}

int sumar_array(int numero) {
	int suma = 0;
	while(numero > 0) {
		suma += numero % 10;
		numero /= 10;
	}
	
	return suma;
	
}

int restar_array(int numero) {
	int resta = 0;
	while(numero > 0) {
		resta -= numero % 10;
		numero /= 10;
	}
	
	return resta;
	
}

int multiplicar_array(int numero) {
	int multiplicacion = 0;
	while(numero > 0) {
		multiplicacion *= numero % 10;
		numero /= 10;
	}
	
	return multiplicacion;
	
}

int dividir_array(int numero) {
	int division = 0;
	while(numero > 0) {
		division /= numero % 10;
		numero /= 10;
	}
	
	return division;
	
}


void detectar_teclado() {
	while(1) {
		uint8_t status = insb(0x64);
		if(status & 0x01) {
			uint8_t scancode = insb(0x60);
			
			if(scancode == 0x02) {
				imprimir_texto("1");
				agregar_numero(1);
				
			} else if(scancode == 0x03) {
				imprimir_texto("2");
				agregar_numero(2);
				
			} else if(scancode == 0x04) {
				imprimir_texto("3");
				agregar_numero(3);
				
			} else if(scancode == 0x05) {
				imprimir_texto("4");
				agregar_numero(4);
				
			} else if(scancode == 0x06) {
				imprimir_texto("5");
				agregar_numero(5);
				
			} else if(scancode == 0x07) {
				imprimir_texto("6");
				agregar_numero(6);
				
			} else if(scancode == 0x08) {
				imprimir_texto("7");
				agregar_numero(7);
				
			} else if(scancode == 0x09) {
				imprimir_texto("8");
				agregar_numero(8);
				
			} else if(scancode == 0x0A) {
				imprimir_texto("9");
				agregar_numero(9);
				
			} else if(scancode == 0x0B) {
				imprimir_texto("0");
				agregar_numero(0);
				
			} else if(scancode == 0x38) {
				app_calculadora = false;
				kernel_main();
			}
			if(scancode == 0x1E) {
		        imprimir_texto("a");
		        agregar_caracter('a');

		    } else if(scancode == 0x30) {
		        imprimir_texto("b");
		        agregar_caracter('b');

		    } else if(scancode == 0x2E) {
		        imprimir_texto("c");
		        agregar_caracter('c');


		    } else if(scancode == 0x20) {
		        imprimir_texto("d");
		        agregar_caracter('d');


		    } else if(scancode == 0x12) {
		        imprimir_texto("e");
		        agregar_caracter('e');


		    } else if(scancode == 0x21) {
		        imprimir_texto("f");
		        agregar_caracter('f');


		    } else if(scancode == 0x22) {
		        imprimir_texto("g");
		        agregar_caracter('g');


		    } else if(scancode == 0x23) {
		        imprimir_texto("h");
		        agregar_caracter('h');


		    } else if(scancode == 0x17) {
		        imprimir_texto("i");
		        agregar_caracter('i');


		    } else if(scancode == 0x24) {
		        imprimir_texto("j");
		        agregar_caracter('j');


		    } else if(scancode == 0x25) {
		        imprimir_texto("k");
		        agregar_caracter('k');


		    } else if(scancode == 0x26) {
		        imprimir_texto("l");
		        agregar_caracter('l');


		    } else if(scancode == 0x32) {
		        imprimir_texto("m");
		        agregar_caracter('m');


		    } else if(scancode == 0x31) {
		        imprimir_texto("n");
		        agregar_caracter('n');


		    } else if(scancode == 0x18) {
		        imprimir_texto("o");
		        agregar_caracter('o');


		    } else if(scancode == 0x19) {
		        imprimir_texto("p");
		        agregar_caracter('p');


		    } else if(scancode == 0x10) {
		        imprimir_texto("q");
		        agregar_caracter('q');


		    } else if(scancode == 0x13) {
		        imprimir_texto("r");
		        agregar_caracter('r');


		    } else if(scancode == 0x1F) {
		        imprimir_texto("s");
		        agregar_caracter('s');


		    } else if(scancode == 0x14) {
		        imprimir_texto("t");
		        agregar_caracter('t');


		    } else if(scancode == 0x16) {
		        imprimir_texto("u");
		        agregar_caracter('u');


		    } else if(scancode == 0x2F) {
		        imprimir_texto("v");
		        agregar_caracter('v');


		    } else if(scancode == 0x11) {
		        imprimir_texto("w");
		        agregar_caracter('w');


		    } else if(scancode == 0x2D) {
		        imprimir_texto("x");
		        agregar_caracter('x');


		    } else if(scancode == 0x15) {
		        imprimir_texto("y");
		        agregar_caracter('y');


		    } else if(scancode == 0x2C) {
		        imprimir_texto("z");
		        agregar_caracter('z');


		    } else if(scancode == 0x39) {
		        imprimir_texto(" ");

		    } else if(scancode == 0x0F) {
		        imprimir_texto("    ");

		    } else if(scancode == 0x34) {
		        imprimir_texto(".");

		    
		    } else if(scancode == 0x1A) {
		        imprimir_texto("[");

		    } else if(scancode == 0x1B) {
		        imprimir_texto("]");

		    } else if(scancode == 0x0D) {
		        imprimir_texto("=");

		    } else if(scancode == 0x27) {
		        imprimir_texto(";");

		    } else if(scancode == 0x33) {
		        imprimir_texto(",");

		    } else if(scancode == 0x0C) {
		        imprimir_texto("-");

		    } else if(scancode == 0x4E) {
		        imprimir_texto("+");

		    } else if(scancode == 0x1C) {
		    	if(app_calculadora == false) {
		    		if(strncmp(opcion, "suma", 4) == 0) {
					limpiar_pantalla();
					strcpy(opcion_alargada, opcion);
					app_calculadora = true;
					sumar();
					
				} else if(strncmp(opcion, "resta", 5) == 0) {
					limpiar_pantalla();
					strcpy(opcion_alargada, opcion);
					app_calculadora = true;
					restar();
					
				} else if(strncmp(opcion, "multiplicacion", 14) == 0) {
					limpiar_pantalla();
					strcpy(opcion_alargada, opcion);
					app_calculadora = true;
					multiplicar();
					
				} else if(strncmp(opcion, "division", 8) == 0) {
					limpiar_pantalla();
					strcpy(opcion_alargada, opcion);
					app_calculadora = true;
					dividir();
					
				} else if(strncmp(opcion, "", 1) == 0) {
					imprimir_texto("\n> ");
				}
				else {
					imprimir_texto("\nError, opcion invalida\n\n> ");
				}
				pos_caracteres = 0;
				opcion[0] = '\0';
		    	
		    	} else {
		    		int resultado = 0;
    				char buffer[100];
				for (int i = 0; i < pos_numeros; i++) {
		    			if (strncmp(opcion_alargada, "suma", 4) == 0) {
						for (int i = 0; i < pos_numeros; i++) {
						    resultado += array_numeros[i];
						}
						itoa(resultado, buffer);
						imprimir_texto("\nResultado de la suma: ");
						imprimir_texto(buffer);

					    } else if (strncmp(opcion_alargada, "resta", 5) == 0) {
						resultado = array_numeros[0];
						for (int i = 1; i < pos_numeros; i++) {
						    resultado -= array_numeros[i];
						}
						itoa(resultado, buffer);
						imprimir_texto("\nResultado de la resta: ");
						imprimir_texto(buffer);

					    } else if (strncmp(opcion_alargada, "multiplicacion", 14) == 0) {
						resultado = 1;
						for (int i = 0; i < pos_numeros; i++) {
						    resultado *= array_numeros[i];
						}
						itoa(resultado, buffer);
						imprimir_texto("\nResultado de la multiplicacion: ");
						imprimir_texto(buffer);

					    } else if (strncmp(opcion_alargada, "division", 8) == 0) {
						resultado = array_numeros[0];
						for (int i = 1; i < pos_numeros; i++) {
						    if (array_numeros[i] != 0) {
							resultado /= array_numeros[i];
						    } else {
							imprimir_texto("\nError: división por cero\n");
							return;
						    }
						}
						itoa(resultado, buffer);
						imprimir_texto("\nResultado de la division: ");
						imprimir_texto(buffer);
					    }
					    
					  imprimir_texto("\n\n> ");
					    
		    			pos_numeros = 0;
		    		}
		    		
		    	}
		    }


	}
}
}
