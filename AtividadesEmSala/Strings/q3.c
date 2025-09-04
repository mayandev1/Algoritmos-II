#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char sequencia[10];

    printf("Digite uma sequencia de caracteres:\n");
    scanf("%s", sequencia);
    int N = strlen(sequencia);
    int count = 1;

    printf("Saida: ");
    for (int i = 0; i < N; i++){
        if (sequencia[i] == sequencia[i + 1]){
            count++;
        } else {
            printf("%d%c", count, sequencia[i]);
            count = 1;
        }  
    }
    
    return 0;
}