#include <stdio.h>


int main(){
    int centena, dezena, unidade, num, num2;

    printf("Digite um numero inteiro no formato CDU:\n");
    scanf("%d", &num);

    centena = num/100;
    dezena = (num % 100) / 10;
    unidade = (num % 100) % 10;

    num2 = (unidade * 100) + (dezena * 10) + unidade;

    printf("%d\n", num2);
    return 0;

}