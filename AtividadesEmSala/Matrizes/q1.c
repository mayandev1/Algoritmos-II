#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;

    printf("Digite quais as dimensoes da matriz m x n: \n");
    scanf("%d %d", &m, &n);

    int matriz[m][n];

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
    
    return 0;
}