typedef struct lista_circular ListaCirc;

/*cria uma lista circular vazia*/
ListaCirc* lst_cric_cria();

/*testa se uma lista circular � vazia*/
int lst_circ_vazia(ListaCirc *l);

/*insere um elemento em uma lista circular*/
ListaCirc* lst_circ_insere(ListaCirc *l, int info);

/*busca um elemento em uma lista circular*/
ListaCirc* lst_circ_busca(ListaCirc *l, int info);

/*imprime uma lista circular*/
void lst_circ_imprime(ListaCirc *l);

/*libera o espa�o alocado em uma lista circular*/
void lst_circ_libera(ListaCirc *l);
