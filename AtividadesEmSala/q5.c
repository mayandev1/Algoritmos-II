#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1, num2, temp;

    printf("Digite o numero 1 e o numero 2: ");
    scanf("%d %d", &num1, &num2);

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("%d\n", num1);
    printf("%d\n", num2);

    return 0;
}