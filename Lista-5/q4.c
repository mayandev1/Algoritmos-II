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

typedef struct {
    int id;
    char nome[50];
    char email[50];
    char telefone[50];
    int imovel_id;
} Cliente;

void menu(){
    printf("====== Sistema Atualizado de Gerenciamento Imobiliário ======\n");
    printf("1. Cadastrar imóvel\n");
    printf("2. Listar todos os imóveis\n");
    printf("3. Buscar imóveis por status\n");
    printf("4. Cadastrar cliente\n");
    printf("5. Listar todos os clientes\n");
    printf("6. Comprar imóvel\n");
    printf("7. Listar imóveis vendidos com cliente\n");
    printf("0. Sair\n");
    printf("==============================================================\n");
}

void cadastrarImovel(Imovel imoveis[], int quantidade){
    printf("========== Cadastro de Imóvel ==========\n");
    imoveis[quantidade].id = quantidade + 1;

    getchar();
    printf("Digite o tipo do imóvel (casa/apartamento): ");
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
    printf("Digite o status (disponível / vendido): ");
    fgets(imoveis[quantidade].status, sizeof(imoveis[quantidade].status), stdin);
    imoveis[quantidade].status[strcspn(imoveis[quantidade].status, "\n")] = '\0';

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

    getchar();
    printf("Digite o status do imóvel que deseja buscar: ");
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

void cadastrarCliente(Cliente clientes[], int quantidade){
    printf("========== Cadastro de Cliente ==========\n");
    clientes[quantidade].id = quantidade + 1;

    getchar();
    printf("Digite o nome completo do cliente: ");
    fgets(clientes[quantidade].nome, sizeof(clientes[quantidade].nome), stdin);
    clientes[quantidade].nome[strcspn(clientes[quantidade].nome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(clientes[quantidade].email, sizeof(clientes[quantidade].email), stdin);
    clientes[quantidade].email[strcspn(clientes[quantidade].email, "\n")] = '\0';

    printf("Digite o telefone: ");
    fgets(clientes[quantidade].telefone, sizeof(clientes[quantidade].telefone), stdin);
    clientes[quantidade].telefone[strcspn(clientes[quantidade].telefone, "\n")] = '\0';

    clientes[quantidade].imovel_id = -1;
    printf("Cliente cadastrado com sucesso! ID: %d\n", clientes[quantidade].id);
}

void listarClientes(Cliente clientes[], int qntClientes){
    if (qntClientes == 0){
        printf("Nenhum cliente cadastrado...\n");
        return;
    }

    printf("======== LISTA DE CLIENTES CADASTRADOS ========\n");
    for (int i = 0; i < qntClientes; i++){
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Email: %s\n", clientes[i].email);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("===============================================\n");
    }
}

void comprarImovel(Imovel imoveis[], int qntImoveis, Cliente clientes[], int qntClientes, int idImovel, int idCliente){
    int clienteEncontrado = 0, imovelEncontrado = 0;

    for (int c = 0; c < qntClientes; c++){
        if (clientes[c].id == idCliente){
            clienteEncontrado = 1;
            for (int j = 0; j < qntImoveis; j++){
                if (imoveis[j].id == idImovel && strcmp(imoveis[j].status, "Disponível") == 0){
                    clientes[c].imovel_id = idImovel;
                    strcpy(imoveis[j].status, "Vendido");
                    printf("Imóvel %d vendido com sucesso para o cliente %d!\n", idImovel, idCliente);
                    imovelEncontrado = 1;
                    break;
                }
            }
            break;
        }
    }

    if (!clienteEncontrado){
        printf("Erro: cliente com ID %d não encontrado!\n", idCliente);
    } else if (!imovelEncontrado){
        printf("Erro: imóvel com ID %d não encontrado ou indisponível!\n", idImovel);
    }
}

void listarImoveisVendidos(Imovel imoveis[], int qntImoveis, Cliente clientes[], int qntClientes){
    int vendidos = 0;
    printf("======= IMÓVEIS VENDIDOS =======\n");
    for (int i = 0; i < qntImoveis; i++){
        if (strcmp(imoveis[i].status, "Vendido") == 0){
            for (int j = 0; j < qntClientes; j++){
                if (clientes[j].imovel_id == imoveis[i].id){
                    printf("ID Imóvel: %d\n", imoveis[i].id);
                    printf("Tipo: %s\n", imoveis[i].tipo);
                    printf("Endereço: %s\n", imoveis[i].endereco);
                    printf("Preço: R$ %.2f\n", imoveis[i].preco);
                    printf("Cliente: %s\n", clientes[j].nome);
                    printf("================================\n");
                    vendidos = 1;
                }
            }
        }
    }
    if (!vendidos){
        printf("Nenhum imóvel vendido ainda.\n");
    }
}

int main(){
    SetConsoleOutputCP(65001);
    int nImoveis, nClientes, opcao, quantidadeImoveis = 0, quantidadeClientes = 0, idImovel, idCliente;

    printf("Digite a quantidade de imóveis que podem ser cadastrados: ");
    scanf("%d", &nImoveis);
    printf("Digite a quantidade de clientes que podem ser cadastrados: ");
    scanf("%d", &nClientes);

    Imovel imoveis[nImoveis];
    Cliente clientes[nClientes];
    system("cls");

    do {
        menu();
        printf("Sua opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                if(quantidadeImoveis < nImoveis){
                    system("cls");
                    cadastrarImovel(imoveis, quantidadeImoveis);
                    quantidadeImoveis++;
                } else {
                    printf("Limite máximo de imóveis atingido!\n");
                }
                break;
            case 2:
                system("cls");
                listarImoveis(imoveis, quantidadeImoveis);
                break;
            case 3:
                system("cls");
                buscarImoveis(imoveis, quantidadeImoveis);
                break;
            case 4:
                if (quantidadeClientes < nClientes){
                    system("cls");
                    cadastrarCliente(clientes, quantidadeClientes);
                    quantidadeClientes++;
                } else {
                    printf("Limite máximo de clientes atingido!\n");
                }
                break;
            case 5:
                system("cls");
                listarClientes(clientes, quantidadeClientes);
                break;
            case 6:
                system("cls");
                printf("Digite o ID do Cliente: ");
                scanf("%d", &idCliente);
                printf("Digite o ID do Imóvel: ");
                scanf("%d", &idImovel);
                comprarImovel(imoveis, quantidadeImoveis, clientes, quantidadeClientes, idImovel, idCliente);
                break;
            case 7:
                system("cls");
                listarImoveisVendidos(imoveis, quantidadeImoveis, clientes, quantidadeClientes);
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