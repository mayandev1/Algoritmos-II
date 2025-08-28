#include <stdio.h>
#include <stdlib.h>

int main(){
    float nota;

    printf("Digite sua nota:\n");
    scanf("%f", &nota);

    if (nota >= 9){
        printf("Conceito A.\n");
    }

    if (nota >= 7 && nota <= 8.9){
        printf("Conceito B.\n");
    }
    
    if (nota > 5 && nota <= 6.9){
        printf("Conceito C.\n");
    }

    if (nota < 5){
        printf("Conceito D.\n");
    }
    
    return 0;
}