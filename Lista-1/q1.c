#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, soma = 0, count = 0;
    
    printf("Digite um numero inteiro:\n");
    scanf("%d", &num);

    printf("Soma dos numeros pares:\n");
    for (int i = 1; i <= num; i++){
        if (i % 2 == 0){
            soma = soma + i;
            printf("%d + ", i);

            if (count == 1) {
                printf("%d", i);
            } else {
                printf(" + %d", i);
            }
        } 
    }

    printf("= %d", soma);
}