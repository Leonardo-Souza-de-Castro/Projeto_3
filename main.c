#include <stdio.h>
#include "contatos.h"

int main(){
    int opcao;
    int pos;
    Contatos contatos[TOTAL];

    Erro e = Carregar(contatos, TOTAL, &pos);

    if (e == Abrir)
    {
        printf("Erro: nao foi possivel abrir o arquivo\n");
    }
    else if (e == Ler)
    {
        printf("Erro: nao foi possivel ler os contatos no arquivo\n");
    }
    else if(e == Fechar){
        printf("Erro: nao foi possivel fechar o arquivo\n");
    }

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
            e = Criar(contatos, &pos);

            if (e == Maximo)
            {
                printf("Erro: maximo de contatos alcancado\n");
            }

            break;

        case 2:
            e = Listar(contatos, pos);

            if (e == Sem_contatos)
            {
                printf("Erro: Nao existem contatos para listar\n");
            }
            break;

        case 3:
            e = Deletar(contatos, &pos);

            if (e == Sem_contatos)
            {
                printf("Erro: nao existem contatos para deletar\n");
            }
            else if(e == Nao_existe){
                printf("Erro: nao existe este contato\n");
            }
            break;

        case 0:
            printf("Encerrando Programa!");
            e = Salvar(contatos, TOTAL, pos);

            if (e == Abrir)
            {
                printf("Nao foi possivel abrir o arquivo\n");
            }
            else if (e == Escrever)
            {
                printf("Nao foi possivel escrever os contatos no arquivo.\n");
            }
            else if (e == Fechar)
            {
                printf("Nao foi possivel fechar o arquivo\n");
            }

            break;
        
        default:
            printf("Opcao invalida! \n");
            break;
        }

    } while (opcao != 0);

}