#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista 
{
	int info;
	Lista *prox;
};

/* Cria uma lista vazia.*/
Lista* lst_cria()
{
	return NULL;
}

/* Testa se uma lista é vazia.*/
int lst_vazia(Lista *l)
{
 	return (l==NULL);
}

/* Insere um elemento no início da lista.*/
Lista* lst_insere(Lista *l, int info)
{
 	Lista* ln = (Lista*)malloc(sizeof(Lista));
 	ln->info = info;
 	ln->prox = l;
 	return ln;
}

/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info)
{
 	Lista* lAux = l;
 	while(lAux!=NULL)
 	{
	 	if(lAux->info == info)
 		return lAux;
 		lAux = lAux->prox;
 	}
	 return NULL;
}

/* Imprime uma lista.*/
void lst_imprime(Lista *l)
{
 	Lista* lAux = l;
	 while(lAux!=NULL)
 	{
 		printf("Info = %d\n",lAux->info);
 		lAux = lAux->prox;
 	}
}

Lista* lst_remove(Lista *l, int info)
{
	if(l!=NULL)
	{
 		Lista* lAux = l->prox;
 		if(l->info==info)
		 {
 			free(l);
 			return lAux;
 		}
 	else
	{
	Lista* lAnt = l;
 	while(lAux!=NULL )
	 {
 		if(lAux->info == info)
		{
			lAnt->prox = lAux->prox;
			free(lAux);
			break;
 		}
 		else
		 {
 			lAnt = lAux;
 			lAux = lAux->prox;
 		}
 	} 
 } 
}
return l;
}

/* Libera o espaço alocado por uma lista.*/
void lst_libera(Lista *l)
{
	 Lista* lProx;
	 while(l!=NULL)
	 {
		 lProx = l->prox;
		 free(l);
		 l = lProx;
 	}
}

/*calcula o número de nós da lista*/
int comprimento(Lista *l)
{
	int contador = 0;
	Lista *listaAux = l;
	while(listaAux!=NULL)
	{
		contador++;
		listaAux = listaAux->prox;
	}
	return contador;
}

/*retorna o número de nós da lista que tem o campo info menor que n*/
int menores(Lista* l, int n)
{
	Lista *listaAux = l;
	int contador = 0;
	while(listaAux != NULL)
	{
		if(listaAux->info < n)
		{
			contador++;
		}
		listaAux = listaAux->prox;
	}
	return contador;
}

/*somar todos os campos info da lista*/
int soma (Lista *l)
{
	Lista *listaAux = l;
	int contador = 0;
	while(listaAux != NULL)
	{
		contador += listaAux->info;
		listaAux = listaAux->prox;
	}
	return contador;
}

/*retornar a quantidade de nós com primos*/
int primos(Lista *l)
{
	Lista *listaAux = l;
	int cont = 0;
	int divisores = 0;
	while(listaAux != NULL)
	{
		int n = listaAux->info;
		int i;
		for(i = 0; i < n; i++)
		{
			if(n % (i+1) ==0)
			{
				divisores++;
			}
		}
		if(divisores == 2)
		{
			cont++;
		}
		divisores = 0;
		listaAux = listaAux->prox;
		}
		return cont;	
}

/*concatenar l2 ao final de l1*/
Lista* lst_conc(Lista* l1, Lista* l2)
{
	Lista *listaAux1 = l1;
	Lista *listaProx = listaAux1->prox;
	Lista *listaAnt = l1;
	Lista *listaAux2 = l2;
	while(listaProx != NULL)
	{
		listaAnt = listaProx;
		listaProx = listaProx->prox;
	}
	if(listaProx == NULL)
	{
		listaProx = l2;
		listaAnt->prox = listaProx;
	}
	
	return listaAux1;
}

/*retira de L1 os mesmos elementos que estao em L2*/
Lista* lst_diferenca(Lista* l1, Lista* l2)
{
	Lista *listaRetornada = NULL;
	Lista *listaAux2 = NULL;
	Lista *listaL1 = l1;
	int verifica = 0;
	
	while(listaL1 != 0)
	{
		verifica = 0;
		listaAux2 = l2;
		while(listaAux2 != NULL)
		{
			if(listaL1->info == listaAux2->info)
			{
				verifica = 1;
				break;
			}
			listaAux2 = listaAux2->prox;
		}
		if(verifica == 0)
		{
			listaRetornada = lst_insere(listaRetornada, listaL1->info);
		}
		listaL1 = listaL1->prox;
	}
	
	return listaRetornada;
}

Lista* lst_remove_rec(Lista *l, int info)
{
	if(!lst_vazia(l))
 		if(l->info==info)
		 {
			Lista* lAux = l;
			 l = l->prox;
			free(lAux);
 	}
 	else
	 {
		l->prox = lst_remove_rec(l->prox,info);
	}
return l; 
}

void lst_imprime_invertida_rec(Lista* l)
{
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
 	}
}



