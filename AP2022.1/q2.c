#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int info;
	Lista* prox;
}Lista;

int qtd_lista(Lista* l, int x, int y)
{
	Lista* lAux = l;
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
int main(void)
{
	Lista* l;
	Lista* l2;
	Lista* l3;
	l->info=1;
	l2->info=2;
	l3->info=3;
	l->prox=l2;
	l2->prox=l3;
	l3->prox=NULL;
	qtd_lista(l,2,3);
	
}
