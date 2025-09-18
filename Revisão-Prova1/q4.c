#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    printf("Digite o tamanho do vetor N: ");
    scanf("%d", &N);

    int vetor[N], resultado[N];

    for (int i = 0; i < N; i++){
        printf("Digite o valor do elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    int k = 0;
    for (int i = 0; i < N; i++){
        if (vetor[i] % 2 == 0){
            resultado[k++] = vetor[i];
        }
    }

    for (int i = 0; i < N; i++){
        if (vetor[i] % 2 != 0){
            resultado[k++] = vetor[i];
        }
    }

    printf("\nVetor Reorganizado:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}