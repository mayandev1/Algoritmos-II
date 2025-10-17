#include <stdio.h>
#include <string.h>

#define MAX_PILOTOS 100

typedef struct {
    char nome[50];
    float tempo_volta1;
    float tempo_volta2;
    float tempo_volta3;
    float media;
} Piloto;

void lerDadosPilotos(Piloto pilotos[], int quantidade) {
    printf("\n=== ENTRADA DE DADOS DOS PILOTOS ===\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("\nPiloto %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]", pilotos[i].nome);
        
        printf("Tempo da 1a volta (segundos): ");
        scanf("%f", &pilotos[i].tempo_volta1);
        
        printf("Tempo da 2a volta (segundos): ");
        scanf("%f", &pilotos[i].tempo_volta2);
        
        printf("Tempo da 3a volta (segundos): ");
        scanf("%f", &pilotos[i].tempo_volta3);
        
        if (pilotos[i].tempo_volta1 <= 0 || pilotos[i].tempo_volta2 <= 0 || pilotos[i].tempo_volta3 <= 0) {
            printf("Erro: Os tempos devem ser positivos!\n");
            i--;
        }
    }
}

void calcularMedia(Piloto pilotos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        pilotos[i].media = (pilotos[i].tempo_volta1 + pilotos[i].tempo_volta2 + pilotos[i].tempo_volta3) / 3.0;
    }
}

void ordenarPilotos(Piloto pilotos[], int quantidade) {
    Piloto temp;
    
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (pilotos[j].media > pilotos[j + 1].media) {
                temp = pilotos[j];
                pilotos[j] = pilotos[j + 1];
                pilotos[j + 1] = temp;
            }
        }
    }
}

void exibirTabela(Piloto pilotos[], int quantidade) {
    printf("\n\n=== TABELA FINAL DE RESULTADOS ===\n");
    printf("=============================================\n");
    printf("Posicao | %-20s | Media (s)\n", "Nome do Piloto");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("%-8d | %-20s | %8.2f\n", 
               i + 1, 
               pilotos[i].nome, 
               pilotos[i].media);
    }
    printf("=============================================\n");
}

int main() {
    int quantidade_pilotos;
    Piloto pilotos[MAX_PILOTOS];
    
    printf("=== COMPETICAO DE AUTOMOBILISMO ===\n\n");
    
    printf("Digite a quantidade de pilotos participantes: ");
    scanf("%d", &quantidade_pilotos);
    
    if (quantidade_pilotos <= 0 || quantidade_pilotos > MAX_PILOTOS) {
        printf("Quantidade de pilotos invalida! (1-%d)\n", MAX_PILOTOS);
        return 1;
    }
    
    lerDadosPilotos(pilotos, quantidade_pilotos);
    calcularMedia(pilotos, quantidade_pilotos);
    ordenarPilotos(pilotos, quantidade_pilotos);
    exibirTabela(pilotos, quantidade_pilotos);
    
    return 0;
}