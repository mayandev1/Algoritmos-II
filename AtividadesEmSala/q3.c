#include <stdio.h>
#include <stdlib.h>

int main(){
    float mediaPonderada = 0, nota1, nota2, nota3;
    int peso1, peso2, peso3;

    printf("Digite o valor da nota 1, 2 e 3: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    printf("Digite o valor do peso 1, 2 e 3: ");
    scanf("%d %d %d", &peso1, &peso2, &peso3);

    mediaPonderada = (nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3) / (peso1 + peso2 + peso3);

    printf("Sua media ponderada eh igual a %.2f\n", mediaPonderada);
    return 0;
}