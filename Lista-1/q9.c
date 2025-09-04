#include <stdio.h>
#include <stdlib.h>

int main(){
    int valorSaque;

    printf("Digite o valor que quer sacar (valor int positivo): ");
    scanf("%d", &valorSaque);

    if (valorSaque % 5 != 0){
        printf("ERRO, DIGITE UM MULTIPLO DE 5\n");
        return 1;
    } 
    
    int notas100 = 0, notas50 = 0, notas20 = 0, notas10 = 0, notas5 = 0;
    notas100 = valorSaque / 100;
    valorSaque = valorSaque % 100;

    notas50 = valorSaque / 50;
    valorSaque = valorSaque % 50;

    notas20 = valorSaque / 20;
    valorSaque = valorSaque % 20;

    notas10 = valorSaque / 10;
    valorSaque = valorSaque % 10;

    notas5 = valorSaque / 5;

    printf("Notas de 100: %d\n", notas100);
    printf("Notas de 50: %d\n", notas50);
    printf("Notas de 20: %d\n", notas20);
    printf("Notas de 10: %d\n", notas10);
    printf("Notas de 5: %d\n", notas5);
    
    return 0;
}