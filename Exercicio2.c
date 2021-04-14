#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int tamMaxTexto = 1000;
    int qtdProdutos;
    int cod;
    char nome[tamMaxTexto];
    double valor;
    char * linha[tamMaxTexto];
    FILE * arqCriaP;
    FILE * arqLerP;
    FILE * arquivoP;
    char buffer[tamMaxTexto];

    arqLerP = fopen("./arquivo.txt", "r");

    if(arqLerP == NULL) {
        arqLerP = fopen("./arquivo.txt", "w");
        arqLerP = fopen("./arquivo.txt", "r");
    }

    arquivoP = fopen("./arquivo.txt", "a");

    if(arquivoP == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite a quantidade de produtos: \n");
    scanf("%i", &qtdProdutos);

    for(int i = 0; i < qtdProdutos; i++) {
        printf("Digite o código do produto \n");
        scanf("%i", &cod);
        printf("Digite o nome do produto \n");
        scanf("%s", nome);
        printf("Digite o valor do produto \n");
        scanf("%lf", &valor);

        fprintf(arquivoP, "%d", cod);
        fprintf(arquivoP, "%s", ",");
        fprintf(arquivoP, "%s", nome);
        fprintf(arquivoP, "%s", ",");
        fprintf(arquivoP, "%.2f", valor);
        fprintf(arquivoP, "%s", "\n");
    }

    fclose(arquivoP);

    printf("Arquivo criado/editado com sucesso :) \n");

    return 0;
}