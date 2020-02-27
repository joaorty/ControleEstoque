#include "produtos.h"
#include "geral.c"
#include <stdio.h>
#include <stdlib.h>

int numerodeProdutos(float qtd, FILE *p)
{
    p = fopen("Produtos.txt", "r");
    qtd = 0;
    char c;
    while(c != EOF)
    {
        c = getc(p);
        if(c == '#') {qtd++;}
    }
    fclose(p);
    return qtd;
}

int menu(int aux)
{
    printf("\tControle de Estoque\n");
    printf("Digite a opcao desejada: \n");
    printf("1-Adicionar Produto\n2-Vender produtos\n3-Lucro obtido ate o momento\n4-Sair\n5-Atualizar lista de produto\n\n");
    printf("\tOpcao: ");
    scanf("%d", &aux);
    if(aux > 0 && aux < 5) {
        system("cls");
    }
    return aux;
}

int continuarPrograma(void)
{
    limpa(void);
    char aux;
    printf("Deseja continuar usando o programa? (S/N): ");
    scanf("%c", &aux);
    system("cls");
    if(aux == 's' || aux == 'S') {
        return 1;
    } else {
        return 0;
    }
}

int qntsProdutos(int max)
{
    printf("Digite quantos produtos quer adicionar (max 100): ");
    scanf("%d", &max);
    return max;
}

char *recebeNome(char *str)
{
    limpa();
    str = malloc(32 * sizeof(char));
    printf("Digite o nome do produto: ");
    scanf("%s", str);
    return str;
}

int recebeQtd(int qtd)
{
    limpa();
    printf("Digite a quantidade do produto disponivel: ");
    scanf("%d", &qtd);
    return qtd;
}

float recebeValor(float valor)
{
    limpa();
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    return valor;
}

void adicionarDados(char *nome, int qtd, float valor, FILE *p)
{
    p = fopen("Produtos.txt", "a");
    fprintf(p, "#%s ", nome);
    fprintf(p, "%d ", qtd);
    fprintf(p, "%.2f \n", valor);
    fclose(p);
}

int escolherProdutoVenda(int qtd)
{
    int aux;
    printf("\tOpcao: ");
    scanf("%d", &aux);
    aux-=1;
    if(aux > qtd) {
        while(aux > qtd)
        {
            printf("Erro: numero selecionado nao foi encontrado.\nPor favor, digite uma opcao acima: ");
            scanf("%d", &aux);
        }
    }
    return aux;
}

char *atualizarNome(char *str)
{
    str = malloc(100 * sizeof(char));
    fscanf(p, "%s", str);
    return str;
}

int atualizarQtd()
{
    char qtd[16];
    fscanf(p, "%s", qtd);
    return atoi(qtd);
}

float atualizarValor()
{
    char valor[16];
    fscanf(p, "%s", valor);
    return atof(valor);
}

void sobrescreverDados(int qtd, float valor, char *nome, FILE *p)
{
    p = fopen("Produtos.txt", "a");
    fprintf(p, "%s ", nome);
    fprintf(p, "%d ", qtd);
    fprintf(p, "%.2f \n", valor);
    fclose(p);
}
