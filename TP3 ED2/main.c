
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Cadeia.h"
#include "ForcaBruta.h"
#include "BM.h"
#include "BMH.h"
#include "BMHS.h"
#include "ShiftAndExato.h"

int main(int argc, char *argv[])
{
    clock_t inicio, fim, total;
    double tempo;
    int op;
    char nome[20];
    long comp = 0, desloc = 0;
    op = atoi(argv[1]);

    TipoTexto tipoTexto;

    switch (atoi(argv[2]))
    {
    case 1:
    {
        tipoTexto = lerTexto("pequeno.txt");

        break;
    }
    case 2:
    {
        tipoTexto = lerTexto("medio.txt");
        break;
    }
    case 3:
    {
        tipoTexto = lerTexto("grande.txt");
        break;
    }
    default:
    {
        printf("\n\n Erro no tamanho do arquivo escolhido");
        return 0;
        break;
    }
    }
    //padrão a ser pesquisado
    TipoPadrao tipoPadrao = malloc(sizeof(argv[3]));
    strcpy(tipoPadrao, argv[3]);

    //avalia qual método vai ser usado
    switch (op)
    {
    case 1:
    { //força bruta
        inicio = clock();
        printf("\nFORÇA BRUTA");
        if (!ForcaBruta(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nNao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (argv[4] != NULL)
        {
            if (strcmp(argv[4], "[-P]") == 0 || strcmp(argv[4], "[-p]") == 0)
            {
                printf("\nFORÇA BRUTA");
                imprimeAnalize(comp, desloc, tempo);
            }
        }
        break;
    }
    case 2:
    { //boyer-moore
        inicio = clock();
        printf("\nBOYER-MOORE");
        if (!BM(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nNao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (argv[4] != NULL)
        {
            if (strcmp(argv[4], "[-P]") == 0 || strcmp(argv[4], "[-p]") == 0)
            {
                printf("\nBOYER-MOORE");
                imprimeAnalize(comp, desloc, tempo);
            }
        }
        break;
    }
    case 3:
    { //boyer-moore-horspool
        inicio = clock();
        printf("\nBOYER-MOORE-HORSPOOL");
        if (!BMHS(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nNao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (argv[4] != NULL)
        {
            if (strcmp(argv[4], "[-P]") == 0 || strcmp(argv[4], "[-p]") == 0)
            {
                printf("\nBOYER-MOORE-HORSPOOL");
                imprimeAnalize(comp, desloc, tempo);
            }
        }
        break;
    }
    case 4:
    { //boyer-moore-horspool-sunday
        inicio = clock();
        printf("\nBOYER-MOORE-HORSPOOL-SUNDAY");
        if (!BMHS(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nNao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (argv[4] != NULL)
        {
            if (strcmp(argv[4], "[-P]") == 0 || strcmp(argv[4], "[-p]") == 0)
            {
                printf("\nBOYER-MOORE-HORSPOOL");
                imprimeAnalize(comp, desloc, tempo);
            }
        }
        break;
    }
    case 5:
    { //shift-and exato
        inicio = clock();
        printf("\nSHIFT AND EXATO\n");
        if (!ShiftAnd(tipoTexto, strlen(tipoTexto), tipoPadrao, strlen(tipoPadrao), &comp, &desloc))
        {
            printf("\nPadrao nao encontrado\n");
        }

        fim = clock();
        total = fim - inicio;
        tempo = ((double)total) / CLOCKS_PER_SEC;
        if (argv[4] != NULL)
        {
            if (strcmp(argv[4], "[-P]") == 0 || strcmp(argv[4], "[-p]") == 0)
            {
                printf("\nSHIFT AND EXATO\n");
                imprimeAnalize(comp, desloc, tempo);
            }
            break;
        }
    }
    default:
    {
        printf("\n\n Erro no metodo");
        return 0;
        break;
    }
    }



    free(tipoTexto);
    free(tipoPadrao);
    return 0;
}
