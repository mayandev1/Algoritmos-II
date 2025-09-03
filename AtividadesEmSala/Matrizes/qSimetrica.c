#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;

    printf("Digite quantos as dimensoes da matriz n x n: \n");
    scanf("%d %d", &m, &n);

    int matriz[m][n], simetrica = 1;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Digite o elemento: [%d x %d]\n", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    system("cls");

    printf("Matriz\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matriz[i][j] != matriz[j][i]){
                simetrica = 0;
                break;
            }
        }
    }

    if (simetrica){
        printf("A matriz eh simetrica!\n");
    } else {
        printf("A matriz nao eh simetrica!\n");
    }
    
    return 0;
}