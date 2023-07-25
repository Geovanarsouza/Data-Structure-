typedef struct arvb ArvB;

/*fun��o que cria uma arvore binaria de busca vazia*/
ArvB* arvb_cria_vazia(void);

/*testa se uma arvore binaria de busca � vazia*/
int arvb_vazia(ArvB *a);

/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);

/*Fun��o que imprime os elementos de uma �rvore.*/
void arvb_imprime(ArvB *a);

/*Fun��o que insere um inteiro em uma �rvore.*/
ArvB* arvb_insere(ArvB *a, int c); 

/*Fun��o que remove um inteiro em uma �rvore.*/
ArvB* arvb_remove(ArvB *a, int c); 

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a);

/*verifica se um numero � primo*/
int ehPrimo(int numero);

/*retorna a quantidade de nos que possuem o campo info um numero primo*/
int folhas_primos(ArvB* a);

/*retorna a quantidade de nos que possuem os dois filhos diferentes de NULL*/
int dois_filhos(ArvB* a);

/*altura de uma arvore*/
int arvb_altura(ArvB* a);

/*retorna a quantidade de nos cujas sub�rvores esquerda e direita n�o s�o vazia e t�m igual altura*/
int nos_igual_altura(ArvB* a);

/*compara se duas �rvores bin�rias de busca s�o iguais*/
int iguais(ArvB* a, ArvB* b);
