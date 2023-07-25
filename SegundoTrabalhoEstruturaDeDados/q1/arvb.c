#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb
{
	int info;
	ArvB* esq;
	ArvB* dir; 
};

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void)
{
	return NULL;
}

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a)
{
	return a == NULL;
}

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c)
{
	if(arvb_vazia(a))
	{
		return NULL;
	}
	else if(a->info < c)
	{
		arvb_busca(a->dir,c);
	}
	else if(a->info > c)
	{
		arvb_busca(a->esq,c);
	}
	else /*a->info == c*/
	{
		return a;
	}
}

/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a)
{
	if(!arvb_vazia(a))
	{
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
	
}

/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c)
{
	if(arvb_vazia(a))
	{
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->dir = NULL;
		a->esq = NULL;
	}
	else if(a->info > c)
	{
		a->esq = arvb_insere(a->esq, c);
	}
	else if(a->info < c)
	{
		a->dir = arvb_insere(a->dir, c);
	}
	else
	{
		printf("\nElemento Ja Pertence a Arvore");
	}
	return a;
}

ArvB* arvb_remove(ArvB *a, int c)
{
	if(!arvb_vazia(a))
	{
		if(a->info > c)
		{
			a->esq = arvb_remove(a->esq,c);
		}
		else if(a->info < c)
		{
			a->dir = arvb_remove(a->dir,c);
		}
		else
		{
			ArvB* t;
			if(a->esq == NULL)
			{
				t = a;
				a = a->dir;
				free(t);
			}
			else if(a->dir == NULL)
			{
				t = a;
				a = a->esq;
				free(t);
			}
			else
			{
				t = a->esq;
				while(t->dir != NULL)
				{
					t = t->dir;
				}
				a->info = t->info;
				t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

void arvb_libera(ArvB* a)
{
	if(!arvb_vazia(a))
	{
		arvb_libera(a->esq);
		arvb_libera(a->dir);
	}
	free(a);	
}

int ehPrimo(int numero)
{
	/*não é primo*/
	if(numero <= 1)
	{
		return 0;
	}
	int a = numero/2;
	int cont = 0;
	int i;
	for(i = 2; i <=a; i++)
	{
		if(numero % i == 0)
		{
			cont++;
		}
	}
	if(cont == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
int folhas_primos(ArvB* a)
{
	if(a == NULL)
	{
		return 0;
	}
	if(a->esq == NULL && a->dir == NULL)
	{
		return ehPrimo(a->info);
	}
	return folhas_primos(a->esq) + folhas_primos(a->dir);
}

int dois_filhos(ArvB* a)
{
	if(a == NULL)
	{
		return 0;
	}
	
	if(a->esq != NULL && a->dir != NULL)
	{
		return 1 + dois_filhos(a->esq) + dois_filhos(a->dir);
	}
	
	return 0;
}

int arvb_altura(ArvB* a)
{
	if(arvb_vazia(a))
	{
		return -1;
	}
	else
	{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
		{
			return 1 + hSAE;
		}
		else
		{
			return 1 + hSAD;
		}
	}
}

int nos_igual_altura(ArvB* a)
{
	if(arvb_vazia(a))
	{
		return 0;
	}
	
	int cont = 0;
	
	if(a->esq != NULL && a->dir != NULL)
	{
		int altura_esq = arvb_altura(a->esq);
		int altura_dir = arvb_altura(a->dir);
		if(altura_esq == altura_dir)
		{
			cont = 1;
		}
	}
	cont += nos_igual_altura(a->esq) + nos_igual_altura(a->dir);
	return cont;
}

int iguais(ArvB* a, ArvB* b)
{
	if(arvb_vazia(a) && arvb_vazia(b))
	{
		return 1;
	}
	else if(arvb_vazia(a) || arvb_vazia(b))
	{
		return 0;
	}
	else
	{
		return (a->info == b->info && iguais(a->esq,b->esq)) && iguais(a->dir,b->dir);
	}
	
}
