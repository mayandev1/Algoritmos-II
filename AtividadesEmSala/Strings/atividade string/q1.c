#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    int apenasLetras = 1;

    printf("Digite um conjunto de caracteres: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++){
        if (!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))){
            apenasLetras = 0;
            break;
        }
    }
    
    if (apenasLetras){
        printf("Apenas letras!\n");
    } else {
        printf("Contem outros caracteres\n");
    }
    
    return 0;
}  