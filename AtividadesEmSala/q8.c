#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade, universitario;

    printf("Digite a sua idade:\n");
    scanf("%d", &idade);
 
    printf("Voce eh universitario?\n");    
    printf("Digite 1 para 'sim' ou 0 para 'nao'\n");
    scanf("%d", &universitario);
    

    (idade >= 18 && idade < 31 && universitario == 0) ? 
    printf("Voce esta qualificado para o concurso!\n") :
    printf("Voce nao atende aos requisitos do concurso, desculpe. :(\n");
    
    return 0;
}