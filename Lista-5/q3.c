#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 

typedef struct {
    int id;
    char tipo[20];
    char endereco[50];
    float preco;
    int quartos;
    float area;
    char status[20];
} Imovel;

void menu(){
    printf("====== Sistema de Gerenciamento Imobiliário ======\n");
    printf("1. Cadastrar imóvel\n");
    printf("2. Listar todos os imóveis\n");
    printf("3. Buscar imóveis por status\n");
    printf("0. Sair\n");
    printf("==================================================\n");
}

void cadastrarImovel(Imovel imoveis[], int quantidade){
    printf("========== Cadastro de Imóvel ==========\n");

    imoveis[quantidade].id = quantidade + 1;
    
    printf("Digite o tipo do imóvel (casa/apartamento): ");
    getchar();
    fgets(imoveis[quantidade].tipo, sizeof(imoveis[quantidade].tipo), stdin);
    imoveis[quantidade].tipo[strcspn(imoveis[quantidade].tipo, "\n")] = '\0';
    
    printf("Digite o endereço: ");
    fgets(imoveis[quantidade].endereco, sizeof(imoveis[quantidade].endereco), stdin);
    imoveis[quantidade].endereco[strcspn(imoveis[quantidade].endereco, "\n")] = '\0';

    printf("Digite o preço (R$): ");
    scanf("%f", &imoveis[quantidade].preco);

    printf("Digite a quantidade de quartos: ");
    scanf("%d", &imoveis[quantidade].quartos);

    printf("Digite a área (m²): ");
    scanf("%f", &imoveis[quantidade].area);

    getchar(); 
    printf("Digite o status (disponível / vendido / alugado): ");
    scanf("%[^\n]", imoveis[quantidade].status);

    printf("\nImóvel %d cadastrado com sucesso!\n\n", imoveis[quantidade].id);
}

void listarImoveis(Imovel imoveis[], int quantidade){
    if (quantidade == 0){
        printf("Nenhum imóvel cadastrado.\n");
        return;
    }

    printf("======== LISTA DE IMÓVEIS CADASTRADOS ========\n");
    for (int i = 0; i < quantidade; i++){
        printf("ID: %d\n", imoveis[i].id);
        printf("Tipo: %s\n", imoveis[i].tipo);
        printf("Endereço: %s\n", imoveis[i].endereco);
        printf("Preço: R$ %.2f\n", imoveis[i].preco);
        printf("Qtd de quartos: %d\n", imoveis[i].quartos);
        printf("Área: %.2f m²\n", imoveis[i].area);
        printf("Status: %s\n", imoveis[i].status);
        printf("==============================================\n");
    }
}

void buscarImoveis(Imovel imoveis[], int quantidade){
    if (quantidade == 0){
        printf("Nenhum imóvel cadastrado!\n");
        return;
    }

    char status[20];
    int encontrou = 0;

    printf("Digite o status do imóvel que deseja buscar: ");
    getchar(); 
    fgets(status, sizeof(status), stdin);
    status[strcspn(status, "\n")] = '\0'; 

    system("cls");

    for (int i = 0; i < quantidade; i++){
        if (strcmp(imoveis[i].status, status) == 0){
            printf("ID: %d\n", imoveis[i].id);
            printf("Tipo: %s\n", imoveis[i].tipo);
            printf("Endereço: %s\n", imoveis[i].endereco);
            printf("Preço: R$ %.2f\n", imoveis[i].preco);
            printf("Qtd de quartos: %d\n", imoveis[i].quartos);
            printf("Área: %.2f m²\n", imoveis[i].area);
            printf("Status: %s\n", imoveis[i].status);
            printf("==============================================\n");
            encontrou = 1;
        }    
    }

    if (!encontrou){
        printf("Nenhum imóvel com o status '%s' encontrado...\n", status);
    }
}

int main(){
    SetConsoleOutputCP(65001);

    int N, opcao, quantidade = 0;
    printf("Digite a quantidade de imóveis que podem ser cadastrados: ");
    scanf("%d", &N);

    Imovel imoveis[N];
    system("cls");

    do {
        menu();
        printf("Sua opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao){
            case 1:
                if(quantidade < N){
                    system("cls");
                    cadastrarImovel(imoveis, quantidade);
                    quantidade++;
                } else {
                    printf("Limite máximo de imóveis atingido!\n");
                }
                break;

            case 2:
                system("cls");
                listarImoveis(imoveis, quantidade);
                break;

            case 3:
                system("cls");
                buscarImoveis(imoveis, quantidade);
                break;

            case 0:
                system("cls");
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        } 
    } while (opcao != 0);
    
    return 0;
}