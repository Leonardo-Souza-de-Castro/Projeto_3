#include <stdio.h>
#include <string.h>
#include "contatos.h"

Erro Criar(Contatos contatos[], int *pos)
{
    char num_add[13];

    if (*pos >= TOTAL)
    {
        return Maximo;
    }

    do
    {
        printf("Entre com seu nome: ");
        fgets(contatos[*pos].Nome, 70, stdin);
    } while (strlen(contatos[*pos].Nome) == 1);

    do
    {
        printf("Entre com seu sobrenome: ");
        fgets(contatos[*pos].Sobrenome, 50, stdin);
    } while (strlen(contatos[*pos].Sobrenome) == 1);
    do

    {
        printf("Entre com seu email: ");
        fgets(contatos[*pos].Email, 70, stdin);
    } while (!(strstr(contatos[*pos].Email, "@") != NULL && strstr(contatos[*pos].Email, ".") != NULL));

    int i = 0;
    int pos_cont_exis = 0;
    do
    {
        printf("Entre com seu telefone (nao coloque caracteres especiais como () ou -): ");
        scanf("%[^\n]", num_add);
        Clear_buffer();

        i = 0;
        pos_cont_exis = 0;
        for (i; i < *pos; i++)
        {
            if (strcmp(num_add, contatos[i].Telefone) == 0)
            {
                printf("Erro: Este numero ja existe na lista de contatos\n");
                pos_cont_exis = i;
            }
        }
        

    } while (strcmp(num_add, contatos[pos_cont_exis].Telefone) != 0);

    contatos[*pos].Nome[strcspn(contatos[*pos].Nome, "\n")] = 0;
    contatos[*pos].Sobrenome[strcspn(contatos[*pos].Sobrenome, "\n")] = 0;
    contatos[*pos].Email[strcspn(contatos[*pos].Email, "\n")] = 0;
    num_add[strcspn(num_add, "\n")] = 0;
    strcpy(contatos[*pos].Telefone, num_add);

    *pos = *pos + 1;

    return Ok;
}

Erro Deletar(Contatos contatos[], int *pos)
{
    if (*pos == 0)
    {
        return Sem_contatos;
    }

    char num_deletar[13];

    printf("Entre com o numero do contato a ser deletado (nao utilize () ou - ao digitar) sera deletado o primeiro resultado com este numero: ");
    fgets(num_deletar, 12, stdin);

    num_deletar[strcspn(num_deletar, "\n")] = 0;

    int pos_deletar = 0;
    int i = 0;

    for (i; i < *pos; i++)
    {
        if (strcmp(num_deletar, contatos[i].Telefone) == 0)
        {
            printf("Posicao: %d", i + 1);
            printf("\t Nome do Contato: %s %s", contatos[i].Nome, contatos[i].Sobrenome);
            printf("\t Email: %s", contatos[i].Email);
            printf("\t Telefone: %s \n", contatos[i].Telefone);
        }
    }

    printf("Qual posicao do contato a ser deletado? \n");
    scanf("%d", &pos_deletar);

    for (i = pos_deletar - 1; i < *pos; i++)
    {
        printf("%d", i);
        strcpy(contatos[i].Nome, contatos[i + 1].Nome);
        strcpy(contatos[i].Sobrenome, contatos[i + 1].Sobrenome);
        strcpy(contatos[i].Email, contatos[i + 1].Email);
        strcpy(contatos[i].Telefone, contatos[i + 1].Telefone);
    }

    *pos = *pos - 1;

    return Ok;
}

Erro Listar(Contatos contatos[], int pos)
{
    if (pos == 0)
    {
        return Sem_contatos;
    }

    int i = 0;
    for (i; i < pos; i++)
    {
        printf("Posicao: %d", i + 1);
        printf("\t Nome do Contato: %s %s", contatos[i].Nome, contatos[i].Sobrenome);
        printf("\t Email: %s", contatos[i].Email);
        printf("\t Telefone: %s \n", contatos[i].Telefone);
    }
    return Ok;
}

Erro Editar(Contatos contatos[], int *pos){

    if (*pos == 0)
    {
        return Sem_contatos;
    }

    int i = 0;
    for (i; i < *pos; i++)
    {
        printf("Posicao: %d", i + 1);
        printf("\t Nome do Contato: %s %s", contatos[i].Nome, contatos[i].Sobrenome);
        printf("\t Email: %s", contatos[i].Email);
        printf("\t Telefone: %s \n", contatos[i].Telefone);
    }

    int pos_contato = 0;
    printf("Selecione a posicao do contato que deseja editar: \n");
    scanf("%d", &pos_contato);

    char num[12];
    char Nome[70];
    char Sobrenome[50];
    char Email[70];

    printf("Entre com o novo nome (ou aperte enter para manter o antigo): ");
    fgets(Nome, 70, stdin);

    Clear_buffer();

    printf("Entre com o novo sobrenome (ou aperte enter para manter o antigo): ");
    fgets(Sobrenome, 50, stdin);

    do
    {
        printf("Entre com o novo email: ");
        fgets(Email, 70, stdin);
    } while (!(strstr(Email, "@") != NULL && strstr(Email, ".") != NULL));

    i = 0;
    int pos_cont_exis = 0;
    do
    {
        printf("Entre com o novo telefone: ");
        scanf("%[^\n]", num);
        Clear_buffer();

        i = 0;
        pos_cont_exis = 0;
        for (i; i < *pos; i++)
        {
            if (strcmp(contatos[i].Telefone, num) == 0)
            {
                printf("Erro: Este numero ja existe na lista de contatos\n");
                pos_cont_exis = i;
            }
        }
        

    } while (strcmp(num, contatos[pos_cont_exis].Telefone) == 0);

    Nome[strcspn(Nome, "\n")] = 0;
    Sobrenome[strcspn(Sobrenome, "\n")] = 0;
    Email[strcspn(Email, "\n")] = 0;
    num[strcspn(num, "\n")] = 0;

    if (strlen(Nome) > 1)
    {
        strcpy(contatos[pos_contato-1].Nome, Nome);
    }
    else if (strlen(Sobrenome) > 1)
    {
        strcpy(contatos[pos_contato-1].Sobrenome, Sobrenome);
    }
    else if (strlen(Email) > 1)
    {
        strcpy(contatos[pos_contato-1].Email, Email);
    }
    else if (strlen(num) > 1)
    {
        strcpy(contatos[pos_contato-1].Telefone, num);
    }
}

Erro Salvar(Contatos contatos[], int total, int pos)
{
    FILE *f = fopen("contatos", "wb");

    if (f == NULL)
    {
        return Abrir;
    }

    int erro = fwrite(contatos, total, sizeof(Contatos), f);

    if (erro <= 0)
    {
        return Escrever;
    }

    erro = fwrite(&pos, 1, sizeof(int), f);

    if (erro <= 0)
    {
        return Escrever;
    }

    erro = fclose(f);
    if (erro != 0)
    {
        return Fechar;
    }

    return Ok;
}

Erro Carregar(Contatos contatos[], int total, int *pos)
{
    FILE *f = fopen("contatos", "rb");

    if (f == NULL)
    {
        return Abrir;
    }

    int erro = fread(contatos, total, sizeof(Contatos), f);
    if (erro <= 0)
    {
        return Ler;
    }

    erro = fread(pos, 1, sizeof(int), f);
    if (erro <= 0)
    {
        return Ler;
    }

    erro = fclose(f);
    if (erro != 0)
    {
        return Fechar;
    }

    return Ok;
}

void Clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    } // Faz a leitura de tudo que for digitado até que c seja diferente de \n ou EOF(Final do arquivo).
}