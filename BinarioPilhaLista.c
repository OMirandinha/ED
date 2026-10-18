#include <stdio.h>
#include <stdlib.h>

// Definição do Nó da Lista
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Estrutura da Pilha com Lista Encadeada
typedef struct {
    No *topo;
} PilhaLista;

// Inicializa a pilha
void inicializar(PilhaLista *p) {
    p->topo = NULL;
}

// Verifica se está vazia
int estaVazia(PilhaLista *p) {
    return (p->topo == NULL);
}

// Empilha (Push) - Inserção no início da lista
void push(PilhaLista *p, int valor) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Falha na alocacao de memoria (Heap Overflow)!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = p->topo; // O novo nó aponta para o antigo topo
    p->topo = novo;       // O topo agora é o novo nó
}

// Desempilha (Pop) - Remoção do início da lista
int pop(PilhaLista *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia (Underflow)!\n");
        return -1;
    }
    No *aux = p->topo;      // Guarda o nó do topo
    int valor = aux->valor; // Copia o valor
    p->topo = aux->prox;    // O topo desce para o próximo nó
    free(aux);              // Libera a memória do nó removido
    return valor;
}

// Função para liberar toda a memória da pilha (boa prática)
void liberarPilha(PilhaLista *p) {
    while (!estaVazia(p)) {
        pop(p);
    }
}

int main() {
    PilhaLista pilha;
    inicializar(&pilha);

    int numero;
    printf("--- CONVERSOR DECIMAL PARA BINARIO (PILHA LISTA) ---\n");
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

    // Libera qualquer memória restante (embora a pilha já esteja vazia aqui)
    liberarPilha(&pilha);

    return 0;
}
