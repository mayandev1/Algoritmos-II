#include <stdio.h>
#include <stdlib.h>

int main(){
    float temperaturas[7][7], media = 0, maiorMedia = 0, soma = 0, menor;
    int posicaoMenorDia, posicaoMaior;

    printf("Digite as temperaturas:\n");
    for (int i = 0; i < 7; i++){
        printf("Do bairro: %d\n", i+1);
        for (int j = 0; j < 7; j++){
            scanf("%f", &temperaturas[i][j]);
        }
    }

    menor = temperaturas[0][0];

    for (int i = 0; i < 7; i++){
        soma = 0;
        for (int j = 0; j < 7; j++){
            soma += temperaturas[i][j];
            if (temperaturas[i][j] < menor){
                menor = temperaturas[i][j];
                posicaoMenorDia = j;
            }
        }
        
        media = soma/7;
        if (media > maiorMedia){
            maiorMedia = media;
            posicaoMaior = i;
        }
        
    }
    
    printf("Bairro com maior media de temperatura: %d (Media: %.2f)\n", posicaoMaior, maiorMedia);
    printf("Menor temperatura registrada: %.2f (Dia: %d)\n", menor, posicaoMenorDia);

    return 0;
}