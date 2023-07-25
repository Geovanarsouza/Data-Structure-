typedef struct arv Arv;

/*fun��o que cria uma �rvore bin�ria vazia*/
Arv* arv_cria_vazia(void);

/*fun��o que cria um n� em uma �rvore bin�ria*/
Arv* arv_cria_no(char c, Arv *sae, Arv *sad);

/*testa se uma �rvore bin�ria � vazia*/
int arv_vazia(Arv *a);

/*fun��o que imprime os elementos de uma �rvore bin�ria*/
void arv_imprime(Arv *a);

/*fun��o que determina se um caractere pertence a �rvore*/
int arv_pertence(Arv *a, char c);

/*libera o espa�o alocado por uma �rvore bin�ria*/
void arv_libera(Arv *a);

/*calcula a altura de uma arvore binaria*/
int arv_altura(Arv *a);
