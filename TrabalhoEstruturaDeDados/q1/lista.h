typedef struct lista Lista;

/* Cria uma lista vazia.*/
Lista* lst_cria(); 

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l); 

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info); 

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info); 

/* Imprime uma lista.*/
void lst_imprime(Lista *l); 

/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info); 

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l);

/*calcula o número de nós da lista*/
int comprimento(Lista *l);

/*retorna o número de nós da lista que tem o campo info menor que n*/
int menores(Lista* l, int n);

/*somar todos os campos info da lista*/
int soma (Lista *l);

/*retornar a quantidade de nós com primos*/
int primos(Lista *l);

/*concatenar l2 ao final de l1*/
Lista* lst_conc(Lista* l1, Lista* l2);

/*retira de L1 os mesmos elementos que estao em L2*/
Lista* lst_diferenca(Lista* l1, Lista* l2);

Lista* lst_remove_rec(Lista *l, int info);

void lst_imprime_invertida_rec(Lista* l);




