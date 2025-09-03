#include <stdio.h>
#include <stdlib.h>

int main(){
    float coefA, coefB, coefC, Y = 0; 
    int negativos = 0;

    printf("Digite o valor dos coeficientes A, B e C:\n");
    scanf("%f %f %f", &coefA, &coefB, &coefC);

    printf("Valores de X com Y positivo: ");
    for (int X = -10; X <= 10; X++){
        Y = 0;
        Y = (coefA * X * X) + (coefB * X) + coefC;
        if (Y > 0){
            printf("%d ", X);
        } else if (Y < 0){
            negativos++;
        }
    }

    printf("\nQuantidade de valores negativos de y: %d", negativos);
    return 0;
}