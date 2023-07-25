#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct lista
{
	int info;
	Lista *prox;
};

struct fila
{
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void)
{
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f == NULL)
	{
		printf("Memória Insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere(Fila *f, int info)
{
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL)
	{
		printf("Memória Insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f))
	{
		f->fim->prox = l;
	}
	else
	{
		f->ini = l;
	}
	f->fim = l;
}

int fila_vazia(Fila *f)
{
	return f->ini == NULL;
}

int fila_remove(Fila *f)
{
	Lista *l; int a;
 	if(fila_vazia(f))
 	{
 		printf("Fila Vazia!!!\n");
 		exit(1);
	 }
	 a = f->ini->info;
	 l = f->ini;
	 f->ini = f->ini->prox;
	 free(l);
	 if(fila_vazia(f))
	 {
	 	f->fim = NULL;
	 }
	 return a;
}

void fila_imprime(Fila *f)
{
	Lista *lAux = f->ini;
	while(lAux != NULL)
	{
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

void fila_libera(Fila *f)
{
	Lista* l = f->ini;
	Lista* lAux;
	while(l!=NULL)
	{
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}

/*retorna o número de elementos maior que n*/
int qtd_maior(Fila* f, int n)
{
	int cont = 0;
	Lista *lAux = f->ini;
	while(lAux != NULL)
	{
		if(lAux->info > n)
		{
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}

/*cria uma fila com os elementos na ordem inversa*/
Fila* inverte(Fila* f)
{
	Fila* fAux = fila_cria();
	Lista* l = f->ini;	
	while(l != NULL)
	{
		fila_insere(fAux,l->info);
		l = l->prox;
	}
	return fAux;
}

/*retornar o numero de info pares*/
int pares(Fila* f)
{
	int cont = 0;
	Lista *lAux = f->ini;
	while(lAux != NULL)
	{
		if(lAux->info % 2 == 0)
		{
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}
