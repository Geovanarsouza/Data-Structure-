typedef struct lista Lista;

/*cria uma lista vazia*/
Lista* criarLista();

/*testa se uma lista é vazia*/
int testaListaVazia(Lista *lista);

/*insere um elemento no inicio da lista*/
Lista* insereElementoLista(Lista *lista, int info);

/*busca elemento em uma lista*/
Lista* buscarElemento(Lista *lista, int info);

/*imprime uma lista*/
void imprimirLista(Lista *lista);

/*remove um elemento de uma lista*/
Lista* removerElemento(Lista *lista, int info);

/*libera o espaço alocado de uma lista*/
void liberarEspaco(Lista *lista);

/*insere o elemento de forma ordenada*/
Lista* insereElementoOrdenado(Lista *lista, int info);

/*imprime a lista usando recursao*/
void listaImprimeRecursao(Lista *lista);

/*imprime os campos info da lista de tras ra frente*/
void listaImprimeInvertidaRecursao(Lista *lista);

/*remove um elemento por recursao*/
Lista* listaRemoveRecursao(Lista* lista, int info);

/*libera o espaço alocado por recursao*/
void liberaListaRecursao(Lista *lista);

/*testa se duas listas são iguais*/
int listaIgualRecursao(Lista *lista1, Lista *lista2);

/*retorna a quantidade de elementos menores que y e maiores que x*/
int qtd_lista(Lista* l, int x, int y);

/*adiciona um novo nó no fim da lista*/
Lista* insere_fim_lista(Lista* l, int x);
