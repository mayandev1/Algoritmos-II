#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, quantosPrimos = 0, divisores = 0;

    while (1){
        printf("Digite um numero inteiro (sair = -1): ");
        scanf("%d", &num);

        if (num == -1){
            break;
        }

        divisores = 0;
        for (int i = 1; i <= num; i++){
            if (num % i == 0){
                divisores++;
            }    
        }

        printf("O numero %d tem %d divisores!\n", num, divisores);
        
        if (divisores == 2){
            quantosPrimos++;
        }
    }
    
    printf("Total de primos: %d\n", quantosPrimos);
    return 0;
}