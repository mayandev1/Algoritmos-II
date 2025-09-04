#include <stdio.h>
#include <stdlib.h>

int main(){
    float altura, peso, imc;

    printf("Digite seu peso e altura:\n");
    scanf("%f %f", &peso, &altura);

    imc = peso / (altura * altura);

    if (imc < 18.5){
        printf("IMC: %.2f\n", imc);
        printf("Classificacao: Abaixo do Peso.\n");
    } else if (imc >= 18.5 && imc < 25){
        printf("IMC: %.2f\n", imc);
        printf("Classificacao: Normal.\n");
    } else if (imc >= 25 && imc < 30){
        printf("IMC: %.2f\n", imc);
        printf("Classificacao: Sobrepeso.\n");
    } else {
        printf("IMC: %.2f\n", imc);
        printf("Classificacao: Obeso.\n");
    }
    
    return 0;
}