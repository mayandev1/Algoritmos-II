#include <stdio.h>
#include <stdlib.h>

int main(){
    char resultado[6];
    int numeros[5];

    printf("65 a 122\n");

    for (int i = 0; i < 5; i++){
        do {
            printf("Digite um numero: ");
            scanf("%d", &numeros[i]);
            if (numeros[i] < 65 || numeros[i] > 122){
                printf("ERRO\n");
            }
            
        } while (numeros[i] < 65 || numeros[i] > 122);
        resultado[i] = numeros[i];
    }
    resultado[5] = '\0';
    printf("%s", resultado);

    return 0;
}