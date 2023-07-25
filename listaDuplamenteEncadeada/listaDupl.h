typedef struct lista_dupl ListaDupl;

/*cria uma lista dupla encadeada vazia*/
ListaDupl* lst_dupl_cria();

/*testa se uma lista dupla encadeada é vazia*/
int lst_dupl_vazia(ListaDupl* l);

/*insere um elemento no inicio da lista dula encadeada*/
ListaDupl* lst_dupl_insere(ListaDupl *l, int info);

/*imprime uma lista dupla encadeada*/
void lst_dupl_imprime(ListaDupl *l);

/*busca um elemento em uma lista dupla encadeada*/
ListaDupl* lst_dupl_busca(ListaDupl *l, int info);

/*remove um elemento de uma lista dupla encadeada*/
ListaDupl* lst_dupl_remove(ListaDupl *l, int info);

/*libera o espaço alocado por uma lista duplamente encadeada*/
void lst_dupl_libera(ListaDupl *l);
