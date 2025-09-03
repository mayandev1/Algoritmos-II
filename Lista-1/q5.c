#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, octal = 0, resto, posicao = 1;

    printf("Digite um numero inteiro positivo para converte-lo para octal:\n");
    scanf("%d", &num);

    if (num < 0){
        printf("Erro. Numero Negativo..");
        return 1;
    }

    while (num > 0){
        resto = num % 8;
        octal = resto * posicao + octal; 
        num /= 8;
        posicao *= 10;
    }
    
    printf("Numero octal: %d\n", octal);
    
    return 0;
}