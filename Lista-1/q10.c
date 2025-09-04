#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, soma = 0;

    printf("Digite um numero: ");
    scanf("%d", &num);

    for (int i = 1; i < num; i++){
        if (num % i == 0){
            soma = soma + i;
        }
    }
    
    if (soma == num){
        printf("%d eh um numero perfeito!", num);
    } else {
        printf("%d nao eh um numero perfeito!", num);
    }
    
    return 0;
}