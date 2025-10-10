#include <stdio.h>
#include <stdlib.h>

int main(){
    int soma = 0, A, B, abundante = 0;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &A, &B);

    printf("Numeros abundantes entre %d e %d: \n", A, B);
    for (int i = A; i < B; i++){
        soma = 0;
        for (int j = 1; j < i; j++){
            if (i % j == 0){
                soma += j;
            }
        }
        
        if (soma > i){
            printf("%d ", i);
            abundante = 1;
        }
    }

    if (!abundante){
        printf("Nenhum numero abundante!\n");
    }
    
    return 0;
}