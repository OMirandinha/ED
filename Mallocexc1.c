//Leia um número n e aloque com malloc um vetor de n inteiros.
//Preencha o vetor, mostre a soma dos valores e libere a memória.

#include <stdio.h>

int main(){
    int n;
    int resultado = 0;
    printf("Digite um número inteiro");
    scanf("%d", &n);

    if(n < 0){
        printf("\nNão foi possível alocar");
        return 1;
    }

    int *vet = malloc(n * sizeof(int));

    for(int i = 0; i < n * sizeof(int); i++){
        printf("\n Digite o elemento %d do vetor.", i+1);
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < n * sizeof(int); i++){
        resultado += vet[i];
    }

    printf("A somatória dos valores foi %d", resultado);

    free(vet);
    vet = NULL;

    return 0;
}
