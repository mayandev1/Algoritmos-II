#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    int DDD;
    int numero;
} Telefone;

typedef struct {
    int numero;
    char bairro[50];
    char rua[50];
    char cidade[50];
    char pais[50];
} Endereco;

typedef struct{
    int id;
    char nome[50];
    char email[50];
    Telefone telefone;
    Endereco endereco;
} Contato;

int inserirContato(Contato ctts[], int quantidade){
    if(quantidade >= MAX_CONTATOS){
        printf("Agenda cheia!\n");
        return quantidade;
    }

    int id, duplicado;
    Contato novo;

    do {
        duplicado = 0;
        printf("Digite o id do contato: ");
        scanf("%d", &id);

        for (int j = 0; j < quantidade; j++){
            if (id == ctts[j].id){
                printf("Erro. ID ja existente!\n");
                duplicado = 1;
                break;
            }
        }
    } while (duplicado);

    novo.id = id;

    getchar(); 

    printf("Digite o nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(novo.email, sizeof(novo.email), stdin);
    novo.email[strcspn(novo.email, "\n")] = '\0';

    do {
        printf("Digite o telefone (DDD e numero): ");
        scanf("%d %d", &novo.telefone.DDD, &novo.telefone.numero);

        if (novo.telefone.DDD < 0)
            printf("ERRO: DDD nao pode ser negativo!\n");

    } while (novo.telefone.DDD < 0);

    do {
        printf("Digite o numero da casa: ");
        scanf("%d", &novo.endereco.numero);

        if (novo.endereco.numero < 0)
            printf("ERRO: Numero nao pode ser negativo!\n");

    } while (novo.endereco.numero < 0);

    getchar(); 

    printf("Digite o bairro: ");
    fgets(novo.endereco.bairro, sizeof(novo.endereco.bairro), stdin);
    novo.endereco.bairro[strcspn(novo.endereco.bairro, "\n")] = '\0';

    printf("Digite a rua: ");
    fgets(novo.endereco.rua, sizeof(novo.endereco.rua), stdin);
    novo.endereco.rua[strcspn(novo.endereco.rua, "\n")] = '\0';

    printf("Digite a cidade: ");
    fgets(novo.endereco.cidade, sizeof(novo.endereco.cidade), stdin);
    novo.endereco.cidade[strcspn(novo.endereco.cidade, "\n")] = '\0';

    printf("Digite o pais: ");
    fgets(novo.endereco.pais, sizeof(novo.endereco.pais), stdin);
    novo.endereco.pais[strcspn(novo.endereco.pais, "\n")] = '\0';

    ctts[quantidade] = novo;

    system("cls"); 
    printf("Contato cadastrado com sucesso!\n");
    getchar();
    getchar();

    return quantidade + 1;
}      

int deletarContato(Contato ctts[], int quantidade, int id){
    int encontrado = 0;

    if (quantidade == 0){
        printf("Agenda vazia! Nenhum contato para deletar.\n");
        getchar();
        getchar();
        return quantidade;
    }

    printf("Digite o id do contato que queres deletar: ");
    scanf("%d", &id);

    for (int i = 0; i < quantidade; i++){
        if (ctts[i].id == id){
            encontrado = 1;

            for (int j = 0; j < quantidade - 1; j++){
                ctts[j] = ctts[j+1];
            }

            system("cls");
            printf("Contato com ID %d removido com sucesso!\n", id);
            getchar();
            getchar();

            return quantidade - 1;
        }
    }

    if (!encontrado){
        system("cls");
        printf("ID NAO ENCONTRADO...");
        getchar();
        getchar();
    }

    return quantidade;
}

void listarContatos(Contato ctts[], int quantidade){
    if (quantidade == 0){
        system("cls");
        printf("  Nenhum contato cadastrado!\n");
        getchar();
        getchar();
        return;
    }

    printf("\n=========================================\n");
    printf("  LISTA DE CONTATOS (%d total)\n", quantidade);
    printf("=========================================\n\n");

    for (int i = 0; i < quantidade; i++){
        printf(" ID: %d\n", ctts[i].id);
        printf(" Nome: %s\n", ctts[i].nome);
        printf(" Email: %s\n", ctts[i].email);
        printf(" Telefone: (%d) %d\n", ctts[i].telefone.DDD, ctts[i].telefone.numero);

        printf(" Endereco:\n");
        printf("   Rua: %s, N %d\n", ctts[i].endereco.rua, ctts[i].endereco.numero);
        printf("   Bairro: %s\n", ctts[i].endereco.bairro);
        printf("   Cidade: %s\n", ctts[i].endereco.cidade);
        printf("   Pais: %s\n", ctts[i].endereco.pais);

        printf("=========================================\n\n");
    }

    printf("Fim da lista.\n\n");
    getchar();
    getchar();
}

int main(){
    Contato ctts[100];
    int quantidade = 0, id, opcao;

    do {
        system("cls");
        printf("-------- MENU --------\n");
        printf("1. Inserir um novo contato\n");
        printf("2. Deletar um contato existente\n");
        printf("3. Listar todos os contatos\n");
        printf("4. Sair do programa\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao);
        

        switch (opcao){
        case 1:
            system("cls");
            quantidade = inserirContato(ctts, quantidade);
            break;
        case 2:
            printf("Digite o ID do contato para deletar: ");
            scanf("%d", &id);
            quantidade = deletarContato(ctts, quantidade, id);
            break;
        case 3:
            listarContatos(ctts, quantidade);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    
    
    return 0;
}