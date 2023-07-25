#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

struct lista_circular
{
	int info;
	ListaCirc *prox;
};

/*cria uma lista circular vazia*/
ListaCirc* lst_cric_cria()
{
	return NULL;
}

/*testa se uma lista circular é vazia*/
int lst_circ_vazia(ListaCirc *l)
{
	return (l == NULL);
}

/*insere um elemento em uma lista circular*/
ListaCirc* lst_circ_insere(ListaCirc *l, int info)
{
	ListaCirc *lAux = (ListaCirc*)malloc(sizeof(ListaCirc));
	if(lAux == NULL)
	{
		printf("Memória Insuficiente!!!\n");
		exit(1);
	}
	if(l == NULL)
	{
		lAux->prox = lAux;
	}	
	else
	{
		lAux->prox = l->prox;
		l->prox = lAux;
	}
	return lAux;
}

/*busca um elemento em uma lista circular*/
ListaCirc* lst_circ_busca(ListaCirc *l, int info)
{
	if(l != NULL)
	{
		ListaCirc *lAux = l;
		do
		{
			if(lAux->info == info)
			{
				return lAux;
			}
			lAux = lAux->prox;
		}while(lAux != l);
	}
	return l;
}

/*imprime uma lista circular*/
void lst_circ_imprime(ListaCirc *l)
{
	if(l != NULL)
	{
		ListaCirc *lAux = l;
		printf("Lista De Elementos \n");
		do
		{
			printf("Info = %d\n", lAux->info);
			lAux = lAux->prox;
		}while(lAux != l);
	}
}

/*libera o espaço alocado em uma lista circular*/
void lst_circ_libera(ListaCirc *l)
{
	ListaCirc *lAux;
	while(l != NULL)
	{
		lAux = l->prox;
		free(l);
		l = lAux;
	}
}





