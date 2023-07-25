#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

struct lista
{
	int info;
	Lista *prox;
};

/*cria uma lista vazia*/
Lista* criarLista()
{
	return NULL;
}

/*testa se uma lista é vazia*/
int testaListaVazia(Lista *lista)
{
	return(lista == NULL);
}

/*insere elemento no inicio da lista*/
Lista* insereElementoLista(Lista *lista, int info)
{
	Lista *listaInicio = (Lista*)malloc(sizeof(Lista));
	listaInicio->info = info;
	listaInicio->prox = lista;
	return listaInicio;
	
}

/*busca um elemento em uma lista*/
Lista* buscarElemento(Lista *lista, int info)
{
	Lista *listaAux = lista;
	while(listaAux != NULL)
	{
		if(listaAux->info == info)
		{
			return listaAux;
		}
		listaAux = listaAux->prox;
	}
	return NULL;
}

/*imprime uma lista*/
void imprimirLista(Lista *lista)
{
	Lista *listaAux = lista;
	while(listaAux != NULL)
	{
		printf("%d\n",listaAux->info);
		listaAux = listaAux->prox;
	}
}

Lista* removerElemento(Lista *lista, int info)
{
	if(lista!=NULL)
	{
		Lista *listaPos = lista->prox;
		if(lista->info == info)
		{
			free(lista);
			return listaPos;
		}
		else
		{
			Lista *listaAnt = lista;
			while(listaPos != NULL)
			{
				if(listaPos->info == info)
				{
					listaAnt->prox = listaPos->prox;
					free(listaPos);
					break;
				}
				else
				{
					listaAnt = listaPos;
					listaPos = listaPos->prox;
				}
			}	
		}
	}
	return lista;
}

/*libera o espaço alocado em uma lista*/
void liberaLista(Lista *lista)
{
	Lista *listaProx;
	while(lista != NULL)
	{
		listaProx = lista->prox;
		free(lista);
		lista = listaProx;
	}
}

/*insere um elemento na lista de forma crescente*/
Lista* insereElementoOrdenado(Lista *lista, int info)
{
	Lista *newLista = (Lista*)malloc(sizeof(Lista));
	newLista->info = info;
	if(lista == NULL)
	{
		newLista->prox = NULL;
		return newLista;
	}
	else if(lista->info >= info)
	{
		newLista->prox = lista;
		return newLista;
	}
	else
	{
		Lista *listaAnt = lista;
		Lista *listaProx = lista->prox;
		while(listaProx != NULL && listaProx->info < info)
		{
			listaAnt->prox = newLista;
			listaProx = listaProx->prox;
		}
		listaAnt->prox = newLista;
		newLista->prox = listaProx;
		return lista;
	}
}

/*imprime a lista usando recursao*/
void listaImprimeRecursao(Lista *lista)
{
	if(testaListaVazia(lista))
	{
		return;
	}
	else
	{
		printf("info: %d\n", lista->info);
		listaImprimeRecursao(lista->prox);
	}
}

/*imprime os campos info da lista de tras ra frente*/
void listaImprimeInvertidaRecursao(Lista *lista)
{
	if(testaListaVazia(lista))
	{
		return;
	}
	else
	{
		listaImprimeInvertidaRecursao(lista->prox);
		printf("info: %d\n",lista->info);
	}
}

/*remove um elemento por recursao*/
Lista* listaRemoveRecursao(Lista* lista, int info)
{
	if(!testaListaVazia(lista))
	{
		if(lista->info == info)
		{
			Lista *listaAux = lista;
			lista = lista->prox;
			free(listaAux);
		}
		else
		{
			lista->prox = listaRemoveRecursao(lista->prox,info);
		}
		return lista;
	}
	
}

/*libera o espaço alocado por recursao*/
void liberaListaRecursao(Lista *lista)
{
	if(!testaListaVazia(lista))
	{
		liberaListaRecursao(lista->prox);
		free(lista);
	}
}

/*testa se duas listas são iguais*/
int listaIgualRecursao(Lista *lista1, Lista *lista2)
{
	if(testaListaVazia(lista1) && testaListaVazia(lista2))
	{
		return 1;
	}
	else if(testaListaVazia(lista1) || testaListaVazia(lista2))
	{
		return 0;
	}
	else
	{
		return (lista1->info == lista2->info && listaIgualRecursao(lista1->prox, lista2->prox));
	}
}

int qtd_lista(Lista* l, int x, int y)
{
	Lista *lAux = l;
	int cont = 0;
	while(lAux != NULL)
	{
		if(lAux->info > x)
		{
			cont++;
		}
		if(lAux->info < y)
		{
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}
/*insere um novo nó no fim da lista*/
Lista* insere_fim_lista(Lista* l, int x)
{
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	if(ln == NULL)
	{
		printf("Memória Insuficiente!!!\n");
		exit(1);
	}
	Lista* lAux = l;
	while(lAux->prox != NULL)
	{
		lAux = lAux->prox;
	}
	ln->info = x;
	ln->prox = NULL;
	lAux->prox = ln;
	return l;
}








