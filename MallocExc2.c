//Refaça o exercício 1 usando calloc e imprima o vetor antes de preenchê-lo.
//O que muda em relação ao malloc?

#include <stdio.h>

int main(){
    int tam;
    int resultado = 0;

    printf("\nDigite o tamanho do vetor");
    scanf("%d", &tam);

     if(tam < 0){
        printf("\nNão foi possível alocar");
        return 1;
    }

    int *v = calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){
        printf("%d", v[i]); //Agora todos os valores do vetor são inicializados com 0
    }

    for(int i = 0; i < tam; i++){
        printf("\nDigite o elemento %d", i+1);
        scanf("\n %d", &v[i]);
        resultado += v[i];
    }

    printf("\nA somatória dos valores foi %d", resultado);

    free(v);
    v = NULL;

    return 0;
}
