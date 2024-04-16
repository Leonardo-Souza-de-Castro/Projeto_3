#define TOTAL 255

typedef struct{
    char Nome[70];
    char Sobrenome[50];
    char Email[70];
    char Telefone[11];
} Contatos;

typedef enum erros{Ok, Maximo, Sem_contatos, Nao_existe, Abrir, Fechar, Escrever, Ler} Erro;

Erro Criar(Contatos contatos[], int *pos);
Erro Deletar(Contatos contatos[], int *pos);
Erro Listar(Contatos contatos[], int pos);
void Clear_buffer();
