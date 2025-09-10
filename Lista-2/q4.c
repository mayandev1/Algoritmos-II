#include <stdio.h>

int main(){
    int nA, nB;
    int i, j, k;

    printf("Digite o tamanho do vetor A: ");
    scanf("%d", &nA);

    int vetorA[nA];
    for (int i = 0; i < nA; i++){
        printf("Digite o elemento %d do vetor A (ordenados): ", i);
        scanf("%d", &vetorA[i]);
    }
    
    printf("Digite o tamanho do vetor B: ");
    scanf("%d", &nB);

    int vetorB[nB];
    for (int i = 0; i < nB; i++){
        printf("Digite o elemento %d do vetor B (ordenados): ", i);
        scanf("%d", &vetorB[i]);
    }

    int vetorC[nA + nB];
    i = j = k = 0;

    while (i < nA && j < nB){
        if (vetorA[i] < vetorB[j]){
            vetorC[k++] = vetorA[i++];
        } else {
            vetorC[k++] = vetorB[j++];
        }        
    }
    
    while(i < nA){
        vetorC[k++] = vetorA[i++];
    }

    while(j < nB){
        vetorC[k++] = vetorB[j++];
    }

    printf("Vetor C com vetores A e B ordenados: ");
    for (int i = 0; i < nA + nB; i++){
        printf("%d ", vetorC[i]);
    }
    
    return 0;
}