typedef struct arv Arv;

/*função que cria uma árvore binária vazia*/
Arv* arv_cria_vazia(void);

/*função que cria um nó em uma árvore binária*/
Arv* arv_cria_no(char c, Arv *sae, Arv *sad);

/*testa se uma árvore binária é vazia*/
int arv_vazia(Arv *a);

/*função que imprime os elementos de uma árvore binária*/
void arv_imprime(Arv *a);

/*função que determina se um caractere pertence a árvore*/
int arv_pertence(Arv *a, char c);

/*libera o espaço alocado por uma árvore binária*/
void arv_libera(Arv *a);

/*calcula a altura de uma arvore binaria*/
int arv_altura(Arv *a);
