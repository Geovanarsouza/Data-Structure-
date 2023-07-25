#include <stdio.h>
#include <stdlib.h>
#include "listaDupl.h"

struct lista_dupl
{
	int info;
	ListaDupl *ant;
	ListaDupl *prox;
};

ListaDupl* lst_dupl_insere(ListaDupl *l, int info)
{
	ListaDupl* ln = (ListaDupl*)malloc(sizeof(ListaDupl));
	if(ln == NULL)
	{
		printf("Memoria Insuficiente!!!\n");
		exit(1);
	}
	ln->info = info;
	ln->prox = l;
	ln->ant = NULL;
	if(l != NULL)
	{
		l->ant = ln;
	}
	return ln;
}

ListaDupl* lst_dupl_busca(ListaDupl *l, int info)
{
	ListaDupl* lAux = l;
	while(lAux!= NULL)
	{
		if(lAux->info == info)
		{
			return lAux;
		}
		lAux = lAux->prox;
	}
	return NULL;
}

ListaDupl* lst_dupl_remove(ListaDupl *l, int info)
{
	ListaDupl *lAux = lst_dupl_busca(l,info);
	if(lAux == NULL)
	{
		return l;
	}
	if(lAux == l)
	{
		l = lAux->prox;	
	}	
	else
	{
		lAux->ant->prox = lAux->prox;
	}
	if(lAux->prox != NULL)
	{
		lAux->prox->ant = lAux->ant;
	}
	free(lAux);
	return l;
}
