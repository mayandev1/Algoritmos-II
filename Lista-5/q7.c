#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char texto[100];
} Aluno;

typedef struct {
    char disciplina[20];
    char texto[100];
} Professor;

typedef struct {
    float codigoAuth;
    char texto[100];
} Administrador;

typedef union {
    Aluno aluno;
    Professor professor;
    Administrador admin;
} Mensagem;

typedef struct {
    int tipo;
    Mensagem conteudo;
} Envelope;

int main(){
    Envelope mensagens[3];

    printf("=== Sistema de Mensagens da Universidade ===\n");

    for(int i = 0; i < 3; i++){
        printf("\nMensagem %d:\n", i + 1);
        printf("Digite o tipo de usuario (1 = Aluno, 2 = Professor, 3 = Administrador): ");
        scanf("%d", &mensagens[i].tipo);
        getchar();

        switch(mensagens[i].tipo){
            case 1:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &mensagens[i].conteudo.aluno.matricula);
                getchar();
                printf("Digite a mensagem do aluno: ");
                fgets(mensagens[i].conteudo.aluno.texto, 100, stdin);
                mensagens[i].conteudo.aluno.texto[strcspn(mensagens[i].conteudo.aluno.texto, "\n")] = '\0';
                break;

            case 2:
                printf("Digite a disciplina do professor: ");
                fgets(mensagens[i].conteudo.professor.disciplina, 20, stdin);
                mensagens[i].conteudo.professor.disciplina[strcspn(mensagens[i].conteudo.professor.disciplina, "\n")] = '\0';
                printf("Digite a mensagem do professor: ");
                fgets(mensagens[i].conteudo.professor.texto, 100, stdin);
                mensagens[i].conteudo.professor.texto[strcspn(mensagens[i].conteudo.professor.texto, "\n")] = '\0';
                break;

            case 3:
                printf("Digite o codigo de autenticacao do administrador: ");
                scanf("%f", &mensagens[i].conteudo.admin.codigoAuth);
                getchar();
                printf("Digite a mensagem do administrador: ");
                fgets(mensagens[i].conteudo.admin.texto, 100, stdin);
                mensagens[i].conteudo.admin.texto[strcspn(mensagens[i].conteudo.admin.texto, "\n")] = '\0';
                break;

            default:
                printf("Tipo invalido! Essa mensagem sera ignorada.\n");
                mensagens[i].tipo = 0;
        }
    }

    printf("\n=== Exibindo Mensagens ===\n");

    for(int i = 0; i < 3; i++){
        if(mensagens[i].tipo == 1){
            printf("\n[ALUNO]\n");
            printf("Matricula: %d\n", mensagens[i].conteudo.aluno.matricula);
            printf("Mensagem: %s\n", mensagens[i].conteudo.aluno.texto);
        } 
        else if(mensagens[i].tipo == 2){
            printf("\n[PROFESSOR]\n");
            printf("Disciplina: %s\n", mensagens[i].conteudo.professor.disciplina);
            printf("Mensagem: %s\n", mensagens[i].conteudo.professor.texto);
        } 
        else if(mensagens[i].tipo == 3){
            printf("\n[ADMINISTRADOR]\n");
            printf("Codigo de autenticacao: %.2f\n", mensagens[i].conteudo.admin.codigoAuth);
            printf("Mensagem: %s\n", mensagens[i].conteudo.admin.texto);
        }
    }

    return 0;
}