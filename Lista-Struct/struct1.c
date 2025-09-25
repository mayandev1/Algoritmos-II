#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    int codigo;
    int disponivel;
} Livro;

void CadastrarLivros(Livro livros[], int n){
    for (int i = 0; i < n; i++){
        printf("Digite o titulo do livro %d: ", i+1);
        getchar(); 
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);

        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

        int codigo, duplicado;
        do {
            duplicado = 0;

            printf("Digite o codigo do livro %d: ", i+1);
            scanf("%d", &codigo);

            for (int j = 0; j < i; j++){
                if (livros[j].codigo == codigo){
                    printf("ERRO: Codigo %d ja cadastrado para o livro \"%s\".\n", 
                           codigo, livros[j].titulo);
                    duplicado = 1;
                    break;
                }
            }
        } while (duplicado);

        livros[i].codigo = codigo;
        livros[i].disponivel = 1;
    }

    system("cls"); 
    printf("CADASTRO CONCLUIDO!!\n");
}

void ConsultarLivro(Livro livros[], int n){
    int id;
    int encontrado = 0;

    printf("Digite o id do livro: ");
    scanf("%d", &id);
    
    for (int i = 0; i < n; i++){
        if (id == livros[i].codigo){
            printf("Livro encontrado!\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Codigo: %d\n", livros[i].codigo);

            if (livros[i].disponivel == 1){
                printf("Disponivel: Sim\n");
            } else {
                printf("Disponivel: Nao\n");
            }

            encontrado = 1;
            break; 
        }
    }

    if (!encontrado){
        printf("ID INVALIDO, LIVRO NAO ENCONTRADO!\n");
    }
}

void EmprestarLivro(Livro livros[], int n){
    int id;
    int encontrado = 0;

    printf("Digite o id do livro que deseja emprestar: ");
    scanf("%d", &id);
    
    for (int i = 0; i < n; i++){
        if (id == livros[i].codigo){
            printf("Livro encontrado!\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Codigo: %d\n", livros[i].codigo);

            if (livros[i].disponivel == 1){
                printf("Disponivel: Sim\n");
            } else {
                printf("Disponivel: Nao\n");
            }
            encontrado = 1;
        }
        printf("\nLivro foi emprestado!\n");
        livros[i].disponivel = 0;
        break; 
    }

    if (!encontrado){
        printf("ID INVALIDO, LIVRO NAO ENCONTRADO!\n");
    }
}

int main(){
    int opcao;
    int n;

    printf("Quantos livros deseja cadastrar?\n");
    scanf("%d", &n);

    Livro livros[n];
    system("cls");

    while (opcao != 4){
        printf("MENU\n");
        printf("1. Cadastrar Livros\n");
        printf("2. Consultar Livro\n");
        printf("3. Emprestar Livro\n");
        printf("4. Sair\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao);
    
        switch (opcao){
        case 1:
            system("cls");
            CadastrarLivros(livros, n);
            break;
        case 2:
            system("cls");
            ConsultarLivro(livros, n);
            break;  
        case 3:
            system("cls");
            EmprestarLivro(livros, n);
            break;  
        case 4:
            system("cls");
            printf("Encerrando...\n");
            return 0;
        default:
            printf("ERRO! DIGITE UM NUMERO ENTRE 1 e 4.\n");
            break;
        }
    }

    return 0;
}