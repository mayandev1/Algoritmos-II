#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[10], soma[5], posicao = 9;

    printf("Digite os elementos do vetor de 10 posicoes:\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }

    int i = 0;
    for (int j = 0; j < 5; j++){
        soma[j] = vetor[i] + vetor[posicao];
        posicao--;
        i++;
    }

    printf("Saida:\n");
    for (int i = 0; i < 5; i++){
        printf("%d ", soma[i]);
    }
        
    return 0;
}