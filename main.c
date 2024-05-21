#include <stdio.h>
#include "contatos.h"

int main(){
    int opcao;
    int pos;
    int agenda;
    Contatos contatos[TOTAL];
    Contatos contatos_Trabalho[TOTAL];


    printf("\nQual agenda gostaria de mexer: \n");
    printf("1 - Pessoal \n");
    printf("2 - Trabalho \n");

    scanf("%d", &agenda);
    
    Erro e = Carregar(contatos, TOTAL, &pos, agenda);

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
        printf("4 - Editar Contato \n");
        printf("5 - Trocar Agenda \n");
        printf("0 - Sair \n");
        
        printf("Entre com uma opcao: ");

        scanf("%d", &opcao);
        Clear_buffer();        

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
        case 4:
            e = Editar(contatos, &pos);

            if (e == Sem_contatos)
                {
                    printf("Erro: nao existem contatos para deletar\n");
                }
            break;
        case 5:
            if(agenda == 1){
                agenda = 0;
                e = Carregar(contatos, TOTAL, &pos, agenda);

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
            }
            else{
                agenda = 1;
                e = Carregar(contatos, TOTAL, &pos, agenda);

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
            }
            printf("%d", agenda);
            break;
            

        case 0:
            printf("Encerrando Programa!");
            

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
        
    e = Salvar(contatos, TOTAL, pos, agenda);

    } while (opcao != 0);

}