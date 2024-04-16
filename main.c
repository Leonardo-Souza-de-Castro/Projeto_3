#include <stdio.h>
#include "contatos.h"

int main(){
    int opcao;
    int pos = 0;
    Contatos contatos[TOTAL];

    do
    {
        printf("\nMenu Principal: \n");
        printf("1 - Criar Contato \n");
        printf("2 - Listar Contato \n");
        printf("3 - Deletar Contato \n");
        printf("0 - Sair \n");
        
        printf("Entre com uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            Criar(contatos, &pos);
            break;

        case 2:
            Listar(contatos, pos);
            break;

        case 3:
            Deletar(contatos, &pos);
            break;
        
        default:
            printf("Opcao invalida! \n");
            break;
        }

    } while (opcao != 0);
    

}