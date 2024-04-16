# Projeto 3

## Objetivo:
O projeto 3 é um projeto criado do zero, por nós alunos da disciplina de Ciência da Computação, para testar nossos conhecimento e ser avaliados dentro da disciplina.
O projeto consiste em uma "agenda eletronica", o foco é salvar, listar e deletar contatos, com dados como:
* Nome
* Sobrenome
* Email
* Telefone

## Funcionalidades:
O Projeto apresenta as seguintes funcionalidades:
#### Criar:
A função de criar é responsável por pegar as informações e salvalas na memória.
~~~C
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
~~~
#### Listar:
A função de Listar é responsável por trazer da memória (ou do arquivo .bin) os contatos cadastrados pela função acima
~~~C
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
~~~
#### Deletar:
A função de Deletar remove da memória (ou arquivo) os contatos que a pessoa quiser:
~~~C
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
~~~

#### Salvar:
Essa função é responsavel por salvar a lista de contatos em um arquivo binário.
~~~C
  Erro Salvar(Contatos contatos[],int total, int pos){
    FILE *f = fopen("tarefas", "wb");

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
~~~
#### Carregar:
Essa função é responsavel por carregar a lista de contatos em um arquivo binário.
~~~C
Erro Carregar(Contatos contatos[],int total, int *pos){
    FILE *f = fopen("tarefas", "rb");

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
~~~


## Como compilar e executar:

Para rodar este projeto faça o dowload (ou clone) do mesmo, e abre no programa de sua preferencia para que ele seja executado (Exemplo: Replit, Visual Studio, Visual Studio Code)
após isto execute os seguinte comandos no seu terminal.
~~~
gcc *.c -> Este comando compilara todos os arquivos do programa
.\a.exe -> Comando funciona em computadores windows caso está utilizando mac utilize ./a.out
~~~

Após isto poderá utilizar de todas as funções que estão a sua disposição dentro do terminal, podendo criar, listar, deletar e salvar seus principais contatos 😁

## Colaboradores:
|Midias Sociais:|
|:-------------:|
[Github](https://github.com/Leonardo-Souza-de-Castro)|
|[Linkedin](https://www.linkedin.com/in/leonardo-souza-de-castro/)|
