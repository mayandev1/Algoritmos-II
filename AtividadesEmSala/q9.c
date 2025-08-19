#include <stdio.h>
#include <stdlib.h>

int main(){
    float salarioFixo, valorVendas, salarioTotal;

    printf("Digite o seu salario fixo:\n");
    scanf("%f", &salarioFixo);
    printf("Digite o seu valor de vendas:\n");
    scanf("%f", &valorVendas);

    if (valorVendas <= 1500){
        salarioTotal = salarioFixo + (valorVendas * 0.03);
    } else {
        salarioTotal = salarioFixo + (valorVendas * 0.05) + ((valorVendas - 1500) * 0.05);
    }
    
    printf("Seu salario atual apos a comissao eh de R$%.2f\n", salarioTotal);
    return 0;
}