#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;

    printf("Digite um numero natural:\n");
    scanf("%d", &N);

    for (int i = N; i > 0; i--){
        printf("%d - %d = %d\n", N, i, N - i);
    }
    
    return 0;
}