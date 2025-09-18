#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[4][4];

    printf("Digite os elementos da matriz 4 x 4:\n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("Matriz diagonal secundaria e acima dela:\n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i + j <= 3){
                if (matriz[i][j] % 2 == 0){
                    printf("%d\t", matriz[i][j] * 2);
                } else {
                    printf("%d\t", matriz[i][j]);
                }
            } else {
                printf("\t");   
            }
        }
        printf("\n");
    }
    
    return 0;
}