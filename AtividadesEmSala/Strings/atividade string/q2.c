#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int vetor[5];

    printf("Digite 5 numeros inteiros no intervalo de 65 a 122:\n");
    for (int i = 0; i < 5; i++){
        scanf("%d", &vetor[i]);
    }
    
    char str[5];

    for (int i = 0; str[i] != '\0' ; i++){
        str[i] = vetor[i];
    }
    
    printf("String resultante: ");
    for (int i = 0; str[i] != '\0'; i++){
        printf("%c", str[i]);
    }
    
    return 0;
}