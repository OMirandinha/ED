#include <stdio.h>
#include <stdlib.h>

#define MAX 64 // Tamanho máximo suficiente para a representação binária de inteiros

// Estrutura da Pilha com Vetor
typedef struct {
    int itens[MAX];
    int topo;
} PilhaVetor;

// Inicializa a pilha
void inicializar(PilhaVetor *p) {
    p->topo = -1;
}

// Verifica se está vazia
int estaVazia(PilhaVetor *p) {
    return (p->topo == -1);
}

// Verifica se está cheia
int estaCheia(PilhaVetor *p) {
    return (p->topo == MAX - 1);
}

// Empilha (Push)
void push(PilhaVetor *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia (Overflow)!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

// Desempilha (Pop)
int pop(PilhaVetor *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia (Underflow)!\n");
        return -1;
    }
    int valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

int main() {
    PilhaVetor pilha;
    inicializar(&pilha);

    int numero;
    printf("--- CONVERSOR DECIMAL PARA BINARIO (PILHA VETOR) ---\n");
    printf("Digite um numero inteiro nao negativo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Por favor, digite um numero nao negativo.\n");
        return 1;
    }

    // Caso especial para o número 0
    if (numero == 0) {
        printf("O numero 0 em binario e: 0\n");
        return 0;
    }

    // Processo de divisão e empilhamento dos restos
    int temp = numero;
    while (temp > 0) {
        int resto = temp % 2;
        push(&pilha, resto);
        temp = temp / 2;
    }

    // Desempilhando para formar o binário na ordem correta
    printf("O numero %d em binario e: ", numero);
    while (!estaVazia(&pilha)) {
        printf("%d", pop(&pilha));
    }
    printf("\n");

    return 0;
}
