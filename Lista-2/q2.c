#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[3][3];
    int i, j, k;
    int menorLinha, colunaMenor, maiorColuna;
    int encontrou = 0;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("Digite o elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++){
        menorLinha = matriz[i][0];
        colunaMenor = 0;
        for (j = 1; j < 3; j++){
            if (matriz[i][j] < menorLinha){
                menorLinha = matriz[i][j];
                colunaMenor = j;
            }
        }
        maiorColuna = menorLinha;
        for (k = 0; k < 3; k++){
            if (matriz[k][colunaMenor] > maiorColuna){
                maiorColuna = matriz[k][colunaMenor];
            }
        }
        if (maiorColuna == menorLinha){
            printf("\nPonto de sela encontrado na posicao [%d][%d]: %d\n",
                   i, colunaMenor, menorLinha);
            encontrou = 1;
        }
    }

    if (!encontrou){
        printf("\nPonto de sela nao encontrado!\n");
    }

    return 0;
}