#include <stdio.h>
#include <stdlib.h>

int main(){
    int ladoA, ladoB, ladoC, ehTriangulo = 0, soma = 0;

    printf("Informe os lados A, B e C:\n");
    scanf("%d %d %d", &ladoA, &ladoB, &ladoC);

    if ((ladoA < (soma = ladoB + ladoC)) && (ladoB < (soma = ladoA + ladoC)) &&(ladoC < (soma = ladoA + ladoB))){
        ehTriangulo = 1;
    } else {
        ehTriangulo = 0;
        printf("Nao eh triangulo!\n");
    }

    if (ehTriangulo){
        if (ladoA == ladoB && ladoB == ladoC){
            printf("Eh triangulo equilatero!\n");
        } else if ((ladoA != ladoB || ladoB == ladoC) && (ladoA == ladoB || ladoB != ladoC)){
            printf("Eh triangulo isoceles!\n");
        } else {
            printf("Eh triangulo escaleno!\n");
        }
    }
    
    return 0;
}