#include "lucro.h"
#include "geral.h"
#include <stdio.h>
#include <stdlib.h>

void atualizarLucro(float lucro, FILE *l)
{
    l = fopen("Lucros.txt", "w");
    fprintf(l, "%.2f ", lucro);
    fclose(l);
}

float verLucro(float lucro, FILE *l)
{
    char c, real[128];
    int qtd, aux;
    float a;
    qtd = 0;
    lucro = 0;
    l = fopen("Lucros.txt", "r");
    while(c != EOF)
    {
        c = getc(l);
        if(c == ' ') {qtd++;}
    }
    fclose(l);
    l = fopen("Lucros.txt", "r");
    for(cont = 0; cont < qtd; cont++){
        aux = 0;
        do
        {
            real[aux] = getc(l);
            aux++;
        }while(real[aux-1] != ' ');
        real[aux] = '\0';
        a = atof(real);
        lucro += (a);
    }
    fclose(l);
    return lucro;
}