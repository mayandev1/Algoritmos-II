#include <stdio.h>

int main(){
    int tempoGasto, velocidadeMedia;
    float distancia, quantidadeDeLitros;

    printf("Digite o tempo gasto de viagem: ");
    scanf("%d", &tempoGasto);
    printf("Digite a velocidade media percorrida: ");
    scanf("%d", &velocidadeMedia);

    distancia = tempoGasto * velocidadeMedia;
    quantidadeDeLitros = distancia/12;

    printf("Distancia pecorrida: %.2f", distancia);
    printf("Quantidade de litros: %.2f", quantidadeDeLitros);

    return 0;
}