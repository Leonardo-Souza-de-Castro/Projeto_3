#include <stdio.h>
#include <string.h>
#include "contatos.h"

Erro Criar(Contatos contatos[], int *pos){
    if(*pos >= TOTAL){
        return Maximo;
    }
    Clear_buffer();

    printf("Entre com seu nome: ");
    fgets(contatos[*pos].Nome, 70, stdin);


    printf("Entre com seu sobrenome: ");
    fgets(contatos[*pos].Sobrenome, 50, stdin);

    printf("Entre com seu email: ");
    fgets(contatos[*pos].Email, 70, stdin);

    printf("Entre com seu telefone (não coloque caracteres especiais como () ou -): ");
    fgets(contatos[*pos].Telefone, 12, stdin);

    contatos[*pos].Nome[strcspn(contatos[*pos].Nome, "\n")] = 0;
    contatos[*pos].Sobrenome[strcspn(contatos[*pos].Sobrenome, "\n")] = 0;
    contatos[*pos].Email[strcspn(contatos[*pos].Email, "\n")] = 0;
    contatos[*pos].Telefone[strcspn(contatos[*pos].Telefone, "\n")] = 0;

    Clear_buffer();

    *pos = *pos + 1;

    return Ok;

}

Erro Deletar(Contatos contatos[], int *pos){
    if (*pos == 0)
    {
        return Sem_contatos;
    }

    char num_deletar[11];


    printf("Entre com o numero do contato a ser deletado (nao utilize () ou - ao digitar) sera deletado o primeiro resultado com este numero: ");
    fgets(contatos[*pos].Telefone, 11, stdin);

    contatos[*pos].Telefone[strcspn(contatos[*pos].Telefone, "\n")] = 0;
    Clear_buffer();

    int pos_deletar = 0;
    int i = 0;

    for (i; i < *pos; i++)
    {
        if (strcmp(num_deletar, contatos[i].Telefone) == 0)
        {
            pos_deletar = i-1;
        }
    }
    

    for (i = pos_deletar; i < *pos; i++)
    {
        strcpy(contatos[i].Nome, contatos[i+1].Nome);
        strcpy(contatos[i].Sobrenome, contatos[i+1].Sobrenome);
        strcpy(contatos[i].Email, contatos[i+1].Email);
        strcpy(contatos[i].Telefone, contatos[i+1].Telefone);
    }

    *pos = *pos-1;

    return Ok;
}

Erro Listar(Contatos contatos[], int pos){
    if (pos == 0)
    {
        return Sem_contatos;
    }

    int i = 0;
    for (i; i < pos; i++)
    {
        printf("Posicao: %d", i+1);
        printf("\t Nome do Contato: %s %s", contatos[i].Nome, contatos[i].Sobrenome);
        printf("\t Email: %s", contatos[i].Email);
        printf("\t Telefone: %s \n", contatos[i].Telefone);
    }
    
    
}

Erro Salvar(Contatos contatos[],int total, int pos){
    FILE *f = fopen("contatos", "wb");

    if(f == NULL){
        return Abrir;
    }

    int erro = fwrite(contatos, total, sizeof(Contatos), f);

    if (erro <= 0)
    {
        return Escrever;
    }

    erro = fwrite(&pos, 1, sizeof(int), f);

    if(erro <= 0){
        return Escrever;
    }

    erro = fclose(f);
    if (erro != 0)
    {
        return Fechar;
    }

    return Ok;
}

Erro Carregar(Contatos contatos[],int total, int *pos){
    FILE *f = fopen("contatos", "rb");

    if(f == NULL){
        return Abrir;
    }

    int erro = fread(contatos, total, sizeof(Contatos), f);
    if(erro <= 0){
        return Ler;
    }

    erro = fread(pos, 1, sizeof(int), f);
    if(erro <= 0){
        return Ler;
    }

    erro = fclose(f);
    if(erro != 0){
        return Fechar;
    }

    return Ok;
}

void Clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //Faz a leitura de tudo que for digitado até que c seja diferente de \n ou EOF(Final do arquivo).
}