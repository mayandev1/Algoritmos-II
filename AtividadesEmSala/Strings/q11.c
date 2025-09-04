#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char palavra[100];
    int i = 0, apenasLetras = 1;

    printf("Digite:\n");
    scanf("%[^\n]", palavra);

    while (palavra[i] != '\0'){
        if (!((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z'))){
            apenasLetras = 0;
        }
        i++;
    }
    
    if (apenasLetras){
        printf("Apenas Letras!");
    } else {
        printf("Existem outros!");
    }

    return 0;
}