#include "Cadeia.h"

TipoTexto lerTexto(char* arquivo){
    FILE* file = fopen(arquivo, "r");
    if(file == NULL){
        printf("Erro ao abrir %s\n", arquivo);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int tam = ftell(file);
    rewind(file);
    TipoTexto tipoTexto = malloc(tam*sizeof(char));
    int apontador = 0;
    while(!feof(file)){
        tipoTexto[apontador++] = getc(file);
    }
    return tipoTexto;
}

void imprimeAnalize(long comp, long desloc,double tempo){
    printf("\n Comparacoes : %-7ld",comp);
    printf("\n Deslocamentos realizados na varredura de todo o texto: %-7ld",desloc);
    printf("\n Tempo de execucao: %.3f segundos.",tempo);
}
