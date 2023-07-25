typedef struct fila Fila;

typedef struct lista Lista;

/*fun��o que cria uma Fila*/
Fila* fila_cria(void);

/*testa se uma Fila � vazia*/
int fila_vazia(Fila *f);

/*fun��o que adiciona um elemento em uma Fila*/
void fila_insere(Fila *f, int info);

/*fun��o que remove um elemento de uma Fila*/
int fila_remove(Fila *f);

/*fun��o que imprime os elementos de uma Fila*/
void fila_imprime(Fila *f);

/*libera o espa�o alocado para uma Fila*/
void fila_libera(Fila *f);

/*retorna o n�mero de elementos maior que n*/
int qtd_maior(Fila* f, int n);

/*cria uma fila com os elementos na ordem inversa*/
Fila* inverte(Fila* f);

/*retornar o numero de info pares*/
int pares(Fila* f);

