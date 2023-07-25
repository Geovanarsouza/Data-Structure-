typedef struct arvb ArvB;

/*função que cria uma arvore binaria de busca vazia*/
ArvB* arvb_cria(void);

/*testa se uma arvore binaria de busca é vazia*/
int arvb_vazia(Arv *a);

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);

/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c); 

/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c); 

/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);
