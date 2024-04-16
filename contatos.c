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
    fgets(contatos[*pos].Telefone, 11, stdin);

    contatos[*pos].Nome[strcspn(contatos[*pos].Nome, "\n")] = 0;
    contatos[*pos].Sobrenome[strcspn(contatos[*pos].Sobrenome, "\n")] = 0;
    contatos[*pos].Email[strcspn(contatos[*pos].Email, "\n")] = 0;
    contatos[*pos].Telefone[strcspn(contatos[*pos].Telefone, "\n")] = 0;

    Clear_buffer();

    *pos = *pos + 1;

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

void Clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //Faz a leitura de tudo que for digitado até que c seja diferente de \n ou EOF(Final do arquivo).
}