#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <stdio.h>

typedef struct
{
    int qtd;
    float valor;
    char *nome;
} Produtos; //Struct que possui todos os dados de produtos

int numerodeProdutos(int qtd, FILE *p)
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
} //Conta o número de produtos que existe na lista de produtos

int qntsProdutos(int max)
{
    printf("Digite quantos produtos quer adicionar (max 100): ");
    scanf("%d", &max);
    return max;
} //Pergunta quantos produtos quer se adicionar na lista

char *recebeNome(char *str)
{
    fflush(stdin);
    str = malloc(32 * sizeof(char));
    printf("Digite o nome do produto: ");
    scanf("%s", str);
    return str;
} //Recebe o nome

int recebeQtd(int qtd)
{
    fflush(stdin);
    printf("Digite a quantidade do produto disponivel: ");
    scanf("%d", &qtd);
    return qtd;
} //Recebe a quantidade

float recebeValor(float valor)
{
    fflush(stdin);
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    return valor;
} //Recebe o valor do produto

void adicionarDados(char *nome, int qtd, float valor, FILE *p)
{
    p = fopen("Produtos.txt", "a");
    fprintf(p, "#%s ", nome);
    fprintf(p, "%d ", qtd);
    fprintf(p, "%.2f \n", valor);
    fclose(p);
} //Por fim se utiliza essa função para se adicionar os dados

void receberProduto(char *nome, int qtd, float valor, int max, FILE *p)
{
    for(cont = 0; cont < max; cont++)
    {
        nome = malloc( 32 * sizeof(char) );
        nome = recebeNome(nome);
        qtd = recebeQtd(qtd);
        valor = recebeValor(valor);
        adicionarDados(nome, qtd, valor, p);
        free(nome);
    }
}

int escolherProdutoVenda(int qtd, int aux)
{
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
} //Escolhe o produto para se vender

char *atualizarNome(FILE *p)
{
    char *nome = malloc(100 * sizeof(char));
    fscanf(p, "%s", nome);
    return nome;
} //Atualiza o nome de um indice de registro

int atualizarQtd(FILE *p)
{
    char qtd[16];
    fscanf(p, "%s", qtd);
    return atoi(qtd);
} //Atualizar a quantidade de um indice de registro
float atualizarValor(FILE *p)
{
    char valor[16];
    fscanf(p, "%s", valor);
    return atof(valor);
} //Atualiza o valor de um indice de registro

void atualizarStructs(FILE *p, int qtd, Produtos prod[])
{
    p = fopen("Produtos.txt", "r");
    for(cont = 0; cont < qtd; cont++)
    {
        prod[cont].nome = atualizarNome(p);
        prod[cont].qtd = atualizarQtd(p);
        prod[cont].valor = atualizarValor(p);
    }
    fclose(p);
}

void sobrescreverDados(int qtd, float valor, char *nome, FILE *p)
{
    p = fopen("Produtos.txt", "a");
    fprintf(p, "%s ", nome);
    fprintf(p, "%d ", qtd);
    fprintf(p, "%.2f \n", valor);
    fclose(p);
} //Assim que se vende, se sobrescreve os dados

void mostrarProdutos(Produtos prod[], int qtdProdutos)
{
    printf("\tQual produto quer vender?\n");
    for(cont = 0; cont < qtdProdutos; cont++)
    {
        printf("|%d - %s ", cont+1, prod[cont].nome);
        printf("| %d unidades ", prod[cont].qtd);
        printf("| %.2f reais |\n", prod[cont].qtd);
    }
}

void s(char *nome, int qtd, float valor, FILE *p, int qtdProdutos, Produtos prod[])
{
    for(cont = 0; cont < qtdProdutos; cont++)
    {
        nome = malloc (32 * sizeof(char));
        nome = prod[cont].nome;
        qtd = prod[cont].qtd;
        valor = prod[cont].valor;
        sobrescreverDados(qtd, valor, nome, p);
        free(nome);
    }
}
#endif // PRODUTOS_H
