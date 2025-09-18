#include <stdio.h>

int main(){
    int N, i;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int vetor[N], resultado[N];

    printf("Digite os %d elementos do vetor:\n", N);
    for(i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < N; i++){
        resultado[i] = vetor[i] - vetor[N - 1 - i];
    }

    printf("Vetor resultante:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", resultado[i]);
    }   

    return 0;
}