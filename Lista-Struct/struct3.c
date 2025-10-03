#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int tentativas;
    char nome[50];
} Jogador;

int main(){
    Jogador novoJogador;
    int num;
    
    printf("\nDigite o nome do jogador: \n");
    fgets(novoJogador.nome, sizeof(novoJogador.nome), stdin);
    novoJogador.nome[strcspn(novoJogador.nome, "\n")] = '\0';

    srand(time(NULL));
    int numAleatorio = rand() % 100 + 1;

    
    novoJogador.tentativas = 1;
    do {
        printf("Ola, %s!\n", novoJogador.nome);
        printf("Tente adivinhar o numero (entre 1 e 100): \n");
        scanf("%d", &num);

        if (num == numAleatorio){
            printf("Parabéns, %s! Você acertou o numero em %d tentativas.\n", novoJogador.nome, novoJogador.tentativas);
        } else {
            if (num > numAleatorio){
                system("cls");
                printf("Seu palpite foi maior que o numero sorteado! Tente novamente.\n");
                novoJogador.tentativas++;
                continue;
            }
            
            if (num < numAleatorio){
                system("cls");
                printf("Seu palpite foi menor que o numero sorteado! Tente novamente.\n");
                novoJogador.tentativas++;
                continue;
            }
        }

    } while (num != numAleatorio);
    
    return 0;
}
