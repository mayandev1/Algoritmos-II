#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char A[50], B[50];

    printf("Digite uma palavra:\n");
    scanf("%[^\n]", A);

    int i;
    for (i = 0; A[i] != '\0'; i++){
        B[i] = A[i];
    }
    B[i] = '\0';

    printf("Palavra do Char A: %s\n", A);
    printf("Palavra do Char B: %s\n", B);
    
    return 0;
}