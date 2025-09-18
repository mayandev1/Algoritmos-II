#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, ehPrimo = 0, divisores = 0;

    while (1){
        printf("Digite um numero inteiro (sair = -1):\n");
        scanf("%d", &num);

        if (num == -1){
            break;
        }
        
        if(num <= 1){
            printf("Numero invalido!\n");
            continue;
        }

        divisores = 0;
        for (int i = 2; i < num; i++){
            if (num % i == 0){
                divisores++;
            }
        }

        printf("O numero %d possui %d divisores (excluindo 1 e ele mesmo).\n", num, divisores);

        if (divisores == 0){
            ehPrimo++;
        }
    }
    printf("Quantidade de primos digitada: %d\n", ehPrimo);
    
    return 0;
}