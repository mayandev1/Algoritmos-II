#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    char strAuxiliar[100];

    printf("Digite uma palavra:\n");
    scanf("%s", str);

    int N = strlen(str);

    printf("Saida: ");
    for (int i = 0; i < N; i++){
        if (str[i] == str[i + 1]){
            continue; 
        } else {
            strAuxiliar[i] = str[i];
            printf("%c", strAuxiliar[i]);
        }
    }
    strAuxiliar[N] = '\0';

    return 0;
}