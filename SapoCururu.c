//Feitor por Vitor Hugo e Paulo Takeshi
#include <stdio.h>

int main(){
    int pos[14];
    int posInicial;
    int posAtual;
    int saltos;

    for(int i = 0; i < 14; i++){
        pos[i] = i;
    }

    printf("\nDigite a posição inicial do sapo: ");
    scanf("%d", &posInicial);

    printf("\nQuantos saltos o sapo deve dar?");
    scanf("%d", &saltos);

    int *posI = &posInicial;
    int *posA = &posAtual;
    int *s = &saltos;

    *posA = Salto(*posI, *s);

    int *v = pos[14];
    printf("%d", *v + posA);

    return 0;

}

int Salto(int *pI, int *s){
    if(s <= 0){
        printf("\nEntrada inválida, digite valores positivos.");
    } else{
        *pI += *s;
    }

}
