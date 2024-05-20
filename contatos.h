#define TOTAL 255

typedef struct{
    char Nome[70];
    char Sobrenome[50];
    char Email[70];
    char Telefone[12];
} Contatos;

typedef enum erros{Ok, Maximo, Sem_contatos, Nao_existe, Abrir, Fechar, Escrever, Ler} Erro;

Erro Criar(Contatos contatos[], int *pos);
Erro Deletar(Contatos contatos[], int *pos);
Erro Listar(Contatos contatos[], int pos);
Erro Editar(Contatos contatos[], int *pos);
Erro Salvar(Contatos contatos[],int total, int pos);
Erro Carregar(Contatos contatos[],int total, int *pos);
void Clear_buffer();
