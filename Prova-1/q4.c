#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[5][5], countL = 0;

    printf("Preencha a matriz 5x5 com numeros inteiros entre 0 e 9:\n");
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            do {
                printf("Posicao [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);

                if (matriz[i][j] < 0 || matriz[i][j] > 9){
                    printf("Erro! Digite um numero entre 0 e 9.\n");
                }

            } while (matriz[i][j] < 0 || matriz[i][j] > 9);
        }
    }
    
    for (int i = 0; i < 5; i++){
        for (int j = 1; j < 5; j++){
            if (matriz[i][j] == 0){
                if (matriz[i][j-1] != 0 && matriz[i+1][j] != 0 && matriz[i+1][j+1]){
                    countL++;
                }
            }
        }
    }

    printf("Matriz 5x5:\n");
    for (int i = 0; i < 5; i++){
        for (int j = 1; j < 5; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Quantidade de vezes que os padroes L se repetiram: %d", countL);
    return 0;
}