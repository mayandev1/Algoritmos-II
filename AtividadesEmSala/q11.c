#include <stdio.h>
#include <stdlib.h>

int main(){
    int expo, base, resultado = 1;

    printf("Digite o valor da base e do expoente:\n");
    scanf("%d %d", &base, &expo);

    for (int i = 0; i < expo; i++){
        resultado = resultado * base;
    }
    
    printf("RESULTADO = %d\n", resultado);
    return 0;
}