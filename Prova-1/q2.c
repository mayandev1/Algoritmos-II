#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[10], maior = 0, segundoMaior = 0;

    printf("Digite 10 numeros inteiros: ");
    for (int i = 0; i < 10; i++){
        scanf("%d", &num[i]);
    }
    
    maior = num[0];
    segundoMaior = num[0];
    
    printf("Vetor Original:\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", num[i]);
    }

    for (int i = 0; i < 10; i++){
        if (num[i] > maior){
            maior = num[i];
        }
    }

    for (int i = 0; i < 10; i++){
        if (num[i] < maior && num[i] > segundoMaior){
            segundoMaior = num[i];
        }
    }

    printf("\nO segundo maior numero eh: %d\n", segundoMaior);
    return 0;
}