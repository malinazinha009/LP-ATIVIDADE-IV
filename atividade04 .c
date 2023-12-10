#include <stdio.h>
#include <stdlib.h>


struct ContaBancaria {
    char numeroConta[20];
    char nomeTitular[50];
    double saldo;
    char tipoConta[20];
};


void depositar(struct ContaBancaria* conta, double valor) {
    conta->saldo += valor;
    printf("Depósito de R$%.2f realizado com sucesso.\n", valor);
}


void sacar(struct ContaBancaria* conta, double valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Saldo insuficiente ou valor inválido.\n");
    }
}


void imprimirSaldo(const struct ContaBancaria* conta) {
    printf("Saldo atual da conta %s: R$%.2f\n", conta->numeroConta, conta->saldo);
}

int main() {
   
    struct ContaBancaria minhaConta = {"123456", "João Silva", 1000.0, "Corrente"};

    
    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1 - Depositar dinheiro\n");
        printf("2 - Sacar dinheiro\n");
        printf("3 - Imprimir saldo\n");
        printf("4 - Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                double valorDeposito;
                printf("Digite o valor a ser depositado: R$");
                scanf("%lf", &valorDeposito);
                depositar(&minhaConta, valorDeposito);
                break;
            }
            case 2: {
                double valorSaque;
                printf("Digite o valor a ser sacado: R$");
                scanf("%lf", &valorSaque);
                sacar(&minhaConta, valorSaque);
                break;
            }
            case 3:
                imprimirSaldo(&minhaConta);
                break;
            case 4:
                printf("Saindo do programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 4);

    return 0;
}
