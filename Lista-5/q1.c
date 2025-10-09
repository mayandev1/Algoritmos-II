#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct{
    char nome[50];
    int ataque;
    int defesa;
    int vida;
    int ativo;
} Personagem;

void menu();
void cadastrar(Personagem personagens[], int *qtd);
void remover(Personagem personagens[], int *qtd);
void lutar(Personagem personagens[], int qtd);
int buscar(Personagem personagens[], int qtd, char nome[]);

int main(){
    Personagem personagens[MAX];
    int qtd = 0;
    int opcao;

    do{
        menu();
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                cadastrar(personagens, &qtd);
                break;
            case 2:
                remover(personagens, &qtd);
                break;
            case 3:
                lutar(personagens, qtd);
                break;
            case 4:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    }while(opcao != 4);

    return 0;
}

void menu(){
    printf("\n=== MENU ===\n");
    printf("1. Cadastrar Personagem\n");
    printf("2. Remover Personagem\n");
    printf("3. Iniciar Luta\n");
    printf("4. Sair\n");
    printf("==============\n");
}

void cadastrar(Personagem personagens[], int *qtd){
    if(*qtd >= MAX){
        printf("Limite maximo de personagens atingido!\n");
        return;
    }

    Personagem novo;
    printf("\nNome do personagem: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Ataque: ");
    scanf("%d", &novo.ataque);
    printf("Defesa: ");
    scanf("%d", &novo.defesa);
    printf("Vida: ");
    scanf("%d", &novo.vida);
    getchar();

    novo.ativo = 1;
    personagens[*qtd] = novo;
    (*qtd)++;

    printf("\nPersonagem cadastrado!\n");
    printf("Nome: %s | Ataque: %d | Defesa: %d | Vida: %d\n", novo.nome, novo.ataque, novo.defesa, novo.vida);
}

void remover(Personagem personagens[], int *qtd){
    if(*qtd == 0){
        printf("Nenhum personagem cadastrado!\n");
        return;
    }

    char nome[50];
    printf("Nome do personagem a remover: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int i, pos = -1;
    for(i = 0; i < *qtd; i++){
        if(personagens[i].ativo && strcmp(personagens[i].nome, nome) == 0){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("Personagem nao encontrado!\n");
        return;
    }

    for(i = pos; i < *qtd - 1; i++){
        personagens[i] = personagens[i + 1];
    }
    (*qtd)--;

    printf("Personagem removido com sucesso!\n");
}

int buscar(Personagem personagens[], int qtd, char nome[]){
    for(int i = 0; i < qtd; i++){
        if(personagens[i].ativo && strcmp(personagens[i].nome, nome) == 0){
            return i;
        }
    }
    return -1;
}

void lutar(Personagem personagens[], int qtd){
    if(qtd < 2){
        printf("Eh necessario ao menos 2 personagens para lutar!\n");
        return;
    }

    char nome1[50], nome2[50];
    printf("Nome do primeiro personagem: ");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0';

    printf("Nome do segundo personagem: ");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    int p1 = buscar(personagens, qtd, nome1);
    int p2 = buscar(personagens, qtd, nome2);

    if(p1 == -1 || p2 == -1){
        printf("Um ou ambos os personagens nao foram encontrados!\n");
        return;
    }

    Personagem a = personagens[p1];
    Personagem b = personagens[p2];

    printf("\n=== Iniciando Luta ===\n");
    int rodada = 1;

    while(a.vida > 0 && b.vida > 0){
        printf("\n--- Rodada %d ---\n", rodada);

        int dano1 = a.ataque - b.defesa;
        int dano2 = b.ataque - a.defesa;

        if(dano1 < 0) dano1 = 0;
        if(dano2 < 0) dano2 = 0;

        b.vida -= dano1;
        a.vida -= dano2;

        if(b.vida < 0) b.vida = 0;
        if(a.vida < 0) a.vida = 0;

        printf("%s causou %d de dano em %s\n", a.nome, dano1, b.nome);
        printf("%s causou %d de dano em %s\n", b.nome, dano2, a.nome);

        printf("%s -> Vida: %d\n", a.nome, a.vida);
        printf("%s -> Vida: %d\n", b.nome, b.vida);

        rodada++;
    }

    printf("\n=== Fim da luta! ===\n");
    if(a.vida > b.vida)
        printf("Vencedor: %s\n", a.nome);
    else if(b.vida > a.vida)
        printf("Vencedor: %s\n", b.nome);
    else
        printf("Empate!\n");
}