typedef struct fila Fila;

typedef struct lista Lista;

/*função que cria uma Fila*/
Fila* fila_cria(void);

/*testa se uma Fila é vazia*/
int fila_vazia(Fila *f);

/*função que adiciona um elemento em uma Fila*/
void fila_insere(Fila *f, int info);

/*função que remove um elemento de uma Fila*/
int fila_remove(Fila *f);

/*função que imprime os elementos de uma Fila*/
void fila_imprime(Fila *f);

/*libera o espaço alocado para uma Fila*/
void fila_libera(Fila *f);

/*retorna o número de elementos maior que n*/
int qtd_maior(Fila* f, int n);

/*cria uma fila com os elementos na ordem inversa*/
Fila* inverte(Fila* f);

/*retornar o numero de info pares*/
int pares(Fila* f);

