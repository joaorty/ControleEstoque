#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <stdio.h>

typedef struct
{
    int qtd;
    float valor;
    char *nome;
} Produtos; //Struct que possui todos os dados de produtos

int numerodeProdutos(float qtd, FILE *p); //Conta o número de produtos que existe na lista de produtos
int menu(int aux); //Gerencia o menu
int continuarPrograma(void); //Função booleana que pergunta se o cliente quer continuar no programa
int qntsProdutos(int max); //Pergunta quantos produtos quer se adicionar na lista

char *recebeNome(char *str); //Recebe o nome
int recebeQtd(int qtd); //Recebe a quantidade
float recebeValor(float valor); //Recebe o valor do produto
void adicionarDados(char *nome, int qtd, float valor, FILE *p); //Por fim se utiliza essa função para se adicionar os dados

int escolherProdutoVenda(int qtd); //Escolhe o produto para se vender

char *atualizarNome(char *nome); //Atualiza o nome de um indice de registro
int atualizarQtd(void); //Atualizar a quantidade de um indice de registro
float atualizarValor(void); //Atualiza o valor de um indice de registro

void sobrescreverDados(int qtd, float valor, char *nome, FILE *p) //Assim que se vende, se sobrescreve os dados

#endif // PRODUTOS_H
