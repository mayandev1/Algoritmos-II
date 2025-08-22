#include <stdio.h>
#include <stdlib.h>

int main(){
    int X, Y;

    printf("Informe os valores de X e Y:\n");
    scanf("%d %d", &X, &Y);

    system("cls");
    for (int i = 1; i <= Y; i++){
        printf("%d\t", i);

        if (i % X == 0){
            printf("\n");
        }
        
    }

    return 0;
}