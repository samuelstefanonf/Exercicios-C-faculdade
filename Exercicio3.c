#include <stdio.h>

int main(void) {
    int textSize = 1000;
    char buffer[textSize];
    FILE * arqLerP;
    size_t nread;

    arqLerP = fopen("./arquivo.txt", "r");

    if(arqLerP == NULL) {
        printf("Arquivo não encontrado.");
        return 0;
    }

    while ((nread = fread(buffer, 1, sizeof buffer, arqLerP)) > 0) {
        printf("%s", buffer);

        printf( "\n");
    }

    fclose(arqLerP);
    
    return 0;
}