#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, primo;

    printf("Digite um numero:\n");
    scanf("%d", &num);

    if (num <= 1){
        primo = 0;
    } else {
        for (int i = 2; i <= num/2; i++){
            if (num % i == 0){
                primo = 1;
                break;
            }
        }
    }
    
    if (primo){
        printf("O numero %d eh primo!\n", num);
    } else {
        printf("O numero %d nao eh primo!\n", num);
    }
    
    return 0;
}