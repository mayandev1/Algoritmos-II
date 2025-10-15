#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_DE_CARTAS 52
#define TOTAL_DE_VALORES 13 
#define TOTAL_DE_NAIPES 4
#define TAM_MAX 10

typedef struct {
    char naipe[TAM_MAX];
    char valores[TAM_MAX];
} Carta;

void menu(){
    printf("====== MENU ======\n");
    printf("1 - Exibir baralho em ordem\n");
    printf("2 - Embaralhar e exibir baralho\n");
    printf("3 - Sair\n");
    printf("==================\n");
}

void criarBaralho(Carta baralho[]){
    char valores[TOTAL_DE_VALORES][TAM_MAX] = {
        "As", "Dois", "Tres", "Quatro", "Cinco", "Seis", 
        "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"
    };

    char naipes[TOTAL_DE_NAIPES][TAM_MAX] = {
        "Copas", "Espada", "Ouros", "Paus"
    };

    int count = 0;

    for (int i = 0; i < TOTAL_DE_NAIPES; i++){
        for (int j = 0; j < TOTAL_DE_VALORES; j++){
            strcpy(baralho[count].naipe, naipes[i]);
            strcpy(baralho[count].valores, valores[j]);
            count++;
        }
    }
}    

void embaralhar(Carta baralho[]){
    int j;
    Carta temp;
    srand(time(NULL));

    for (int i = 0; i < TOTAL_DE_CARTAS; i++){
        j = rand() % TOTAL_DE_CARTAS;
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    printf("\nBaralho embaralhado!\n\n");   
}

void exibirBaralho(Carta baralho[]){
    printf("=========== BARALHO ===========\n");

    for (int i = 0; i < TOTAL_DE_CARTAS; i++){
        printf("%s de %s\n", baralho[i].valores, baralho[i].naipe);
    }

    printf("===============================\n\n");
    
}

int main(){
    int opcao;
    Carta baralho[TOTAL_DE_CARTAS];

    criarBaralho(baralho);

    do {
        menu();
        printf("Sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                exibirBaralho(baralho);
                break;
            case 2:
                embaralhar(baralho);
                exibirBaralho(baralho);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 3);
 
    return 0;
}