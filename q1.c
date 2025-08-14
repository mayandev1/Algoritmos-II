#include <stdio.h>
#include <stdlib.h>

void calculadora(){
    char operador, escolha;
    float num1, num2, resultado;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);
    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operador);

    switch(operador){
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '/':
            if(num2 != 0){
                resultado = num1 / num2;
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("Erro: Divisao por zero nao e permitida.\n");
            }
            break;
        default:
            printf("Operador invalido.\n");
    }

    printf("Deseja realizar outra operacao? (s/n): ");
    scanf(" %c", &escolha);
    if(escolha == 's' || escolha == 'S'){
        system("cls");
        calculadora();
    } else {
        printf("Encerrando a calculadora.\n");
    }
}

int main(){
    system("cls");
    printf("Calculadora Simples\n");
    calculadora();
    return 0;
}