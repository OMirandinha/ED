// Feito por Vitor Hugo e Paulo Takeshi

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

int main(){
    unsigned char salas[TAMANHO];
    int tentativas = 5;

    //Sorteia a sala da princesa
    int princesa = rand() % TAMANHO;

    for(int i = 0; i < TAMANHO; i++){
        salas[i] = '#';
    }
    while(tentativas > 0){
        for(int i = 0; i < TAMANHO; i++)
            printf("%c", salas[i]);

        printf("\nOnde está a princesa?");

        procurarPrincesa(princesa, &tentativas);


    }

}

int procurarPrincesa(int *tentativas, int *princesa){
    int res;
    scanf("%d", &res);
    if(res != princesa){
        *tentativas--;
        printf("%d", tentativas);    }
    else{
        printf("Parabéns! Encontrou a princesa!"); }
}
