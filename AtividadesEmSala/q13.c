#include <stdio.h>
#include <stdlib.h>

int main(){
    int termos, temp, a = 0, b = 1;

    printf("Digite quantos termos (min = 7):\n");
    scanf("%d", &termos);
    
    printf("FIBONACCI\n");
    for (int i = 0; i < termos; i++){
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    
    return 0;
}