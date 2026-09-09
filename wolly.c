```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 20
#define VIDAS_INICIAIS 3

int main(void)
{
    unsigned char matriz[TAMANHO][TAMANHO];
    int i, j;
    int vidas = VIDAS_INICIAIS;
    int linha, coluna;
    int wollyLinha, wollyColuna;
    int acertou = 0;

    srand((unsigned int)time(NULL));

    /* Sorteia a posição do Wolly */
    wollyLinha = rand() % TAMANHO;
    wollyColuna = rand() % TAMANHO;

    /* Preenche a matriz */
    for (i = 0; i < TAMANHO; i++)
    {
        for (j = 0; j < TAMANHO; j++)
        {
            matriz[i][j] = '@';
        }
    }

    /* Jogo */
    while (vidas > 0 && !acertou)
    {
        printf("\n========== ONDE ESTA O WOLLY? ==========\n\n");

        /* Mostra os numeros das colunas */
        printf("    ");

        for (j = 0; j < TAMANHO; j++)
        {
            printf("%2d ", j + 1);
        }

        printf("\n");

        /* Mostra a matriz */
        for (i = 0; i < TAMANHO; i++)
        {
            printf("%2d  ", i + 1);

            for (j = 0; j < TAMANHO; j++)
            {
                printf(" %c ", matriz[i][j]);
            }

            printf("\n");
        }

        printf("\nVidas restantes: %d\n", vidas);

      /* Leitura da linha */
    printf("\nDigite a linha (1 a %d): ", TAMANHO);
    scanf("%d", &linha);
    
    if (linha < 1 || linha > TAMANHO)
    {
        printf("\nLinha invalida! Digite um valor entre 1 e %d.\n", TAMANHO);
        continue;
    }
    
    /* Leitura da coluna */
    printf("Digite a coluna (1 a %d): ", TAMANHO);
    scanf("%d", &coluna);
    
    if (coluna < 1 || coluna > TAMANHO)
    {
        printf("\nColuna invalida! Digite um valor entre 1 e %d.\n", TAMANHO);
        continue;
    }

        /*
         * Converte os valores digitados pelo usuario
         * (1 a 20) para indices da matriz (0 a 19).
         */
        linha--;
        coluna--;

        /* Verifica se encontrou o Wolly */
        if (linha == wollyLinha && coluna == wollyColuna)
        {
            matriz[linha][coluna] = 'W';

            printf("\n=====================================\n");
            printf("        VOCE ENCONTROU O WOLLY!\n");
            printf("=====================================\n");

            acertou = 1;
        }
        else
        {
            matriz[linha][coluna] = 'X';

            vidas--;

            printf("\nTente novamente!");

            if (vidas > 0)
            {
                printf(" Voce ainda tem %d vida(s).\n", vidas);
            }
        }
    }

    /* Se o jogador perdeu */
    if (!acertou)
    {
        matriz[wollyLinha][wollyColuna] = 'W';

        printf("\n=====================================\n");
        printf("             VOCE PERDEU!\n");
        printf("=====================================\n");

        printf("\nO Wolly estava na linha %d, coluna %d.\n",
               wollyLinha + 1,
               wollyColuna + 1);
    }

    /* Mostra o tabuleiro final */
    printf("\n\n========== TABULEIRO FINAL ==========\n\n");

    printf("    ");

    for (j = 0; j < TAMANHO; j++)
    {
        printf("%2d ", j + 1);
    }

    printf("\n");

    for (i = 0; i < TAMANHO; i++)
    {
        printf("%2d  ", i + 1);

        for (j = 0; j < TAMANHO; j++)
        {
            printf(" %c ", matriz[i][j]);
        }

        printf("\n");
    }

    printf("\nFim de jogo!\n");

    return 0;
}
