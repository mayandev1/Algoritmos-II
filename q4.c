#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, unidade, dezena, centena;

    printf("Digite o seu numero: ");
    scanf("%d", &num);

    centena = num/100;
    dezena = (num % 100) / 10;
    unidade = (num % 100) % 10;

    printf("%d ", centena);
    printf("%d ", dezena);
    printf("%d ", unidade);

    return 0;
}