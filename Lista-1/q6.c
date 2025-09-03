#include <stdio.h>
#include <stdlib.h>

int main(){
    int ramos;

    printf("Digite a quantidade de ramos:\n");
    scanf("%d", &ramos);

    for (int i = ramos; i > 0; i--){
        for (int j = 0; j < i; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}