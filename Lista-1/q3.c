#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao = 0;
    float num1, num2, soma = 0, div = 0, multi = 0, sub = 0;

    printf("CALCULADORA\n");
    printf("Digite o valor 1:\n");
    scanf("%f", &num1);
    printf("Digite o valor 2:\n");
    scanf("%f", &num2);

    printf("1- Soma\n");
    printf("2- Subtracao\n");
    printf("3- Multiplicacao\n");
    printf("4- Divisao\n");
    printf("Escolha sua operacao: ");
    scanf("%d", &opcao);

    switch (opcao){
    case 1:
        soma = num1 + num2;
        printf("Resultado a operacao eh igual a: %.2f\n", soma);
        break;
    case 2:
        sub = num1 - num2;
        printf("Resultado a operacao eh igual a: %.2f\n", sub);
        break;
    case 3:
        multi = num1 * num2;
        printf("Resultado a operacao eh igual a: %.2f\n", multi);
        break;
    case 4:
        if (num1 == 0 || num2 == 0){
            printf("Erro: Divisao por 0...");
            return 0;
        }

        div = num1 / num2;
        printf("Resultado a operacao eh igual a: %.2f\n", div);
        break;
    
    default:
        printf("Erro: Operacao invalida.");
        break;
    }

    return 0;
}