// Feito por Vitor Hugo e Paulo Takeshi

#include <stdio.h>

#define TAM 14

/* Le e valida o numero de pedras do salto (> 0) */
int ler_salto(void) {
    int passos;
    printf("Quantas pedras o sapo deve avancar? ");
    scanf("%d", &passos);
    while (passos <= 0) {
        printf("Entrada invalida. Digite um valor positivo: ");
        scanf("%d", &passos);
    }
    return passos;
}
int main(void) {
    int pedras[TAM];             
    int *posAtual;               
    int *fim;                    
    int posInicial;              
    int totalSaltos;
    int saltoAtual;
    int mosquitos = 0;

    /* Inicializa o vetor (conteudo apenas ilustrativo) */
    for (int i = 0; i < TAM; i++) {
        pedras[i] = i + 1;        
    }

    /* Ponteiro para a ultima pedra (indice 13 -> pedra 14) */
    fim = pedras + (TAM - 1);

    /* ---- Posicao inicial: usuario digita 1..14 ---- */
    printf("Digite a posicao inicial do sapo (1 a %d): ", TAM);
    scanf("%d", &posInicial);
    while (posInicial < 1 || posInicial > TAM) {
        printf("Posicao invalida. Digite entre 1 e %d: ", TAM);
        scanf("%d", &posInicial);
    }

    /* Ponteiro aponta para a pedra correspondente */
    posAtual = pedras + (posInicial - 1);   

    /* ---- Numero total de saltos ---- */
    printf("Quantos saltos o sapo vai dar? ");
    scanf("%d", &totalSaltos);
    while (totalSaltos <= 0) {
        printf("Valor invalido. Digite um numero positivo de saltos: ");
        scanf("%d", &totalSaltos);
    }

    /* ---- Loop dos saltos ---- */
    for (saltoAtual = 1; saltoAtual <= totalSaltos; saltoAtual++) {
        int passos = ler_salto();       /* sempre > 0 */

        /* Verifica limite ANTES de mover (sem sair do vetor) */
        if (posAtual + passos > fim) {
            printf("\nO sapo chegou ao fim do lago!\n");
            break;
        }

        /* Move o ponteiro com aritmetica de ponteiros */
        posAtual = posAtual + passos;

        /* Desafio extra: 1 mosquito por pedra pulada */
        mosquitos += passos;

        /* Exibe em notacao de pedra 1..14 */
        printf("\n--- Salto %d ---\n", saltoAtual);
        printf("Pedra atual: %ld (de 1 a %d)\n", (posAtual - pedras) + 1, TAM);
        printf("Endereco de memoria: %p\n", (void *)posAtual);
        printf("Pedras avancadas: %d\n", passos);
    }

    printf("\nTotal de mosquitos comidos pelo sapo: %d\n", mosquitos);

    return 0;
}
