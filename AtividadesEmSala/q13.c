#include <stdio.h>
#include <stdlib.h>

int main(){
    int termos, temp, a = 0, b = 1;

    printf("Digite quantos termos (min = 7):\n");
    scanf("%d", &termos);
    

    if (termos < 7){
        printf("ERRO: DIGITE UM NUMERO MAIOR OU IGUAL A 7!\n");
    } else {
        printf("FIBONACCI\n");
        for (int i = 0; i < termos; i++){
            printf("%d ", a);
            temp = a + b;
            a = b;
            b = temp;
        }
    }
    
    return 0;
}