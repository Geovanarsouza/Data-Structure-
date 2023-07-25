typedef struct arvb ArvB;

/*função que cria uma arvore binaria de busca vazia*/
ArvB* arvb_cria_vazia(void);

/*testa se uma arvore binaria de busca é vazia*/
int arvb_vazia(ArvB *a);

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

/*verifica se um numero é primo*/
int ehPrimo(int numero);

/*retorna a quantidade de nos que possuem o campo info um numero primo*/
int folhas_primos(ArvB* a);

/*retorna a quantidade de nos que possuem os dois filhos diferentes de NULL*/
int dois_filhos(ArvB* a);

/*altura de uma arvore*/
int arvb_altura(ArvB* a);

/*retorna a quantidade de nos cujas subárvores esquerda e direita não são vazia e têm igual altura*/
int nos_igual_altura(ArvB* a);

/*compara se duas árvores binárias de busca são iguais*/
int iguais(ArvB* a, ArvB* b);
