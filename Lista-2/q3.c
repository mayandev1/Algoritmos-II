#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, j = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    int vetor[N];
    for (int i = 0; i < N; i++){
        printf("Digite o elemento [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int vetor2[N];
    for (int i = 0; i < N; i++){
        if (vetor[i] % 2 == 0){
            vetor2[j++] = vetor[i];
        }
    }
    
    for (int i = 0; i < N; i++){
        if (vetor[i] % 2 != 0){
            vetor2[j++] = vetor[i];
        }
    }
    
    printf("Vetor ordenado: ");
    for (int i = 0; i < N; i++){
        printf("%d ", vetor2[i]);
    }
    
    return 0;
}