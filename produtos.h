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

int continuarPrograma(void)
{
    fflush(stdin);
    char aux;
    printf("Deseja continuar usando o programa? (S/N): ");
    scanf("%c", &aux);
    system("cls");
    if(aux == 's' || aux == 'S'){return 1;} else {return 0;}
} //Função booleana que pergunta se o cliente quer continuar no programa

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

char *atualizarNome(char *nome)
{
    nome = malloc(100 * sizeof(char));
    fscanf(p, "%s", nome);
    return nome;
} //Atualiza o nome de um indice de registro

int atualizarQtd(void)
{
    char qtd[16];
    fscanf(p, "%s", qtd);
    return atoi(qtd);
} //Atualizar a quantidade de um indice de registro
float atualizarValor(void)
{
    char valor[16];
    fscanf(p, "%s", valor);
    return atof(valor);
} //Atualiza o valor de um indice de registro

void sobrescreverDados(int qtd, float valor, char *nome, FILE *p)
{
    p = fopen("Produtos.txt", "a");
    fprintf(p, "%s ", nome);
    fprintf(p, "%d ", qtd);
    fprintf(p, "%.2f \n", valor);
    fclose(p);
} //Assim que se vende, se sobrescreve os dados

#endif // PRODUTOS_H
