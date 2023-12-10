#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEmEstoque;
};

float calcularValorTotal(const struct Produto* produto) {
    return produto->preco * produto->quantidadeEmEstoque;
}


void realizarCompra(struct Produto* produto, int quantidadeComprada) {
    if (quantidadeComprada > 0 && quantidadeComprada <= produto->quantidadeEmEstoque) {
        produto->quantidadeEmEstoque -= quantidadeComprada;
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
    }
}


void consultarEstoque(const struct Produto* produto) {
    printf("Nome: %s\n", produto->nome);
    printf("Preço: R$%.2f\n", produto->preco);
    printf("Quantidade em estoque: %d\n", produto->quantidadeEmEstoque);
    printf("Valor total em estoque: R$%.2f\n", calcularValorTotal(produto));
}

int main() {
    
    struct Produto meuProduto = {"Produto A", 10.99, 50};

  
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                int quantidadeComprada;
                printf("Digite a quantidade a ser comprada: ");
                scanf("%d", &quantidadeComprada);
                realizarCompra(&meuProduto, quantidadeComprada);
                break;
            }
            case 2:
                consultarEstoque(&meuProduto);
                break;
            case 3:
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}
