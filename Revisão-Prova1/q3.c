#include <stdio.h>
#include <stdlib.h>

int main(){
    int matriz[3][3], maior = 0;

    printf("Digite os elementos da matriz 3 x 3:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Elemento [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > maior){
                maior = matriz[i][j];
            }   
        }
    }
    
    int vetor[maior+1];
    for (int i = 0; i <= maior; i++){
        vetor[i] = 0;
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            vetor[matriz[i][j]]++;
        } 
    }

    printf("Frequencia dos elementos:\n");
    for (int i = 0; i <= maior; i++){
        if (vetor[i] > 0){
            printf("%d: %d\n", i, vetor[i]);
        }
    }

    return 0;
}