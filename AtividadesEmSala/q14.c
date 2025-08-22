#include <stdio.h>
#include <stdlib.h>

int main(){
    int ramos;

    printf("Digite a quantidade de ramos:\n");
    scanf("%d", &ramos);

    for (int i = 0; i < ramos; i++){
        for (int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}