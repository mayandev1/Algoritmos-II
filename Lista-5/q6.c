#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    int inteiro;
    float real;
    char texto[4];
} Teste;

int main(){
    Teste x;

    x.inteiro = 100;
    printf("Inteiro = %d\n", x.inteiro);
    printf("Float = %.2f\n", x.real);
    printf("Char = %s\n", x.texto);
    printf("\n");
    
    x.real = 5.5;
    printf("Inteiro = %d\n", x.inteiro);
    printf("Float = %.2f\n", x.real);
    printf("Char = %s\n", x.texto);
    printf("\n");
    
    strcpy(x.texto, "ABC");
    printf("Inteiro = %d\n", x.inteiro);
    printf("Float = %.2f\n", x.real);
    printf("Char = %s\n", x.texto);
    printf("\n");

    return 0;
}