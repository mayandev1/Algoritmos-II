#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char texto[30] = "Mayan";
    int vogais = 0;
    
    for (int i = 0; texto[i] != '\0'; i++){
        if (texto[i] == 'a' || texto[i] == 'A' || texto[i] == 'e' || texto[i] == 'E' || texto[i] == 'i' ||
            texto[i] == 'I' || texto[i] == 'o' || texto[i] == 'O' || texto[i] == 'u' || texto[i] == 'U'){
            vogais++;
        }
    }
    
    printf("Numero de vogais = %d\n", vogais);
    return 0;
}