// Feito por Vitor Hugo e Paulo Takeshi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

// Protótipo da função
int procurarPrincesa(int princesa, int *tentativas);

int main() {
    unsigned char salas[TAMANHO];
    int tentativas = 5;

    // Inicializa o sorteio
    srand(time(NULL));

    // Sorteia uma sala de 1 até 10
    int princesa = rand() % TAMANHO + 1;

    // Inicializa as salas
    for (int i = 0; i < TAMANHO; i++) {
        salas[i] = '#';
    }

    // Mostra as salas e inicia o jogo
    while (tentativas > 0) {

        for (int i = 0; i < TAMANHO; i++) {
            printf("%c", salas[i]);
        }

        printf("\nOnde está a princesa? ");
        
        procurarPrincesa(princesa, &tentativas);

        printf("\n");
    }

    if (tentativas == 0) {
        printf("Suas tentativas acabaram!\n");
        printf("A princesa estava na sala %d.\n", princesa);
    }

    return 0;
}


// Função recursiva
int procurarPrincesa(int princesa, int *tentativas) {

    int resposta;

    // Lê a tentativa do jogador
    scanf("%d", &resposta);

    // Jogador encontrou a princesa
    if (resposta == princesa) {
        printf("Parabéns! Você encontrou a princesa!\n");
        return 1;
    }

    // Diminui uma tentativa
    (*tentativas)--;

    // Verifica se ainda existem tentativas
    if (*tentativas == 0) {
        return 0;
    }

    // Dá uma pista
    if (resposta < princesa) {
        printf("Procure uma sala MAIOR!\n");
    } else {
        printf("Procure uma sala MENOR!\n");
    }

    printf("Tentativas restantes: %d\n", *tentativas);
    printf("Tente novamente: ");

    // RECUSIVIDADE:
    // a função chama ela mesma
    return procurarPrincesa(princesa, tentativas);
}
