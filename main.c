#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lucro.h"
#include "produtos.h"

int continuarPrograma()
{
    fflush(stdin);
    char aux;
    printf("Deseja continuar usando o programa? (S/N): ");
    scanf("%c", &aux);
    system("cls");
    if(aux == 's' || aux == 'S'){return 1;} else {return 0;}
} //Função booleana que pergunta se o cliente quer continuar no programa

int menu()
{
    int aux;
    printf("\tControle de Estoque\n");
    printf("Digite a opcao desejada: \n");
    printf("1-Adicionar Produto\n2-Vender produtos\n3-Lucro obtido ate o momento\n4-Sair\n\n");
    printf("\tOpcao: ");
    scanf("%d", &aux);
    if(aux > 0 && aux < 5) {
        system("cls");
    }
    return aux;
}

int main()
{
    int op, max, qtd, qtdProdutos, aux, continuar = 1;
    FILE *p, *l;
    float valor, lucro = 0;
    char *nome;
    qtdProdutos = numerodeProdutos(qtd, p);
    Produtos lista[qtdProdutos];
    setlocale(LC_ALL, "Portuguese");
    do
    {
        op = menu();
        switch(op)
        {
        case 1:
            max = qntsProdutos(max);
            receberProduto(nome, qtd, valor, max, p);
            break;
        case 2:
            if(qtdProdutos == 0)
            {
                printf("Sinto muito, sem produtos no momento\n\n");
                system("pause");
                system("cls");
                break;
            }
            atualizarStructs(p, qtd, lista);
            mostrarProdutos(lista, qtdProdutos);
            aux = escolherProdutoVenda(qtdProdutos, aux);
            printf("Digite quantas unidades quer vender: ");
            scanf("%d", &qtd);
            if(qtd > lista[aux].qtd)
            {
                while(qtd > lista[aux].qtd)
                {
                    printf("Quantidade maior que o esperado, digite outra quantidade: ");
                    scanf("%d", &qtd);
                }
            }
            lista[aux].qtd -= qtd;
            lucro = recebeLucro(lista[aux].valor, qtd, lucro);
            atualizarLucro(lucro, l);
            p = fopen("Produtos.txt", "w");
            fclose(p);
            s(nome, qtd, valor, p, qtdProdutos, lista[qtdProdutos]);
            continuar = continuarPrograma();
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    }while(op > -1 && op < 5);
    return 0;
}
