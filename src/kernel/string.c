void strcpy(char* destino, const char* origen) {
    while (*origen) {
        *destino++ = *origen++;
    }
    *destino = '\0';
}

