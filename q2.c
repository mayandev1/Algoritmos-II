#include <stdio.h>
#include <stdlib.h>

int main(){
    float salario, novoSalario;

    printf("Digite o seu salario atual:\n");
    scanf("%f", &salario);
    
    novoSalario = salario * 1.25;

    printf("Seu novo salario e igual a %.2f\n", novoSalario);
    return 0;
}