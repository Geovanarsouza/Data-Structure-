#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 3

typedef struct pilha
{
	int n;
	int v[MAX];
}Pilha;

/*Função que cria uma pilha*/
Pilha* pilha_cria(void)
{
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	if(p == NULL)
	{
		printf("Memoria Insuficiente!!!\n");
		exit(1);
	}
	p->n = 0;
	return p;
}

/*Testa se uma pilha é vazia*/
int pilha_vazia(Pilha *p)
{
	return p->n == 0;
}

/*Função que adiciona um elemento no topo de uma pilha*/
void pilha_push(Pilha *p, int info)
{
	if(p->n == MAX)
	{
		printf("Capacidade da Pilha Estourou!!!\n");
		exit(1);
	}
	p->v[p->n] = info;
	p->n = p->n + 1;
}

/*Função que remove um elemento do topo de uma pilha*/
int pilha_pop(Pilha *p)
{
	int a;
	if(pilha_vazia(p))
	{
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	a = p->v[p->n-1];
	p->n--;
	return a;
}

/*Função que imprime os elementos de uma pilha*/
void pilha_imprime(Pilha *p)
{
	int i;
	for(i = p->n-1; i>=0; i--)
	{
		printf("%d\n",p->v[i]);
	}
}

/*Libera o espaço alocado para uma pilha*/
void pilha_libera(Pilha *p)
{
	free(p);
}

/*função que retorna o valor no topo de uma pilha*/
int topo(Pilha *p)
{
	int a = p->v[p->n-1];
	return a;
}

/*retorna a quantidade de elementos da pilha com valor impar*/
int impares(Pilha* p)
{
	int cont = 0;
	int i;
	for(i = p->n-1; i >=0; i--)
	{
		if(p->v[i] % 2 == 1)
		{
			cont++;
		}
	}
	return cont;
}

/*verifica os elementos pares de uma pilha e os empilha em ordem crescente em outra pilha*/
Pilha* empilha_pares(Pilha *p1, Pilha *p2)
{
	int i;
	for(i = p1->n-1; i >= 0; i--)
	{
		if(p1->v[i] % 2 == 0)
		{
			pilha_push(p2,p1->v[i]);
		}
	}
	int a;
	int j;
	for(i = p2->n-1; i >= 0; i--)
	{
		a = p2->v[i];
		for(j = i-1; j >= 0; j--)
		{
			if(p2->v[i] > p2->v[j])
			{
				p2->v[i] = p2->v[j];
				p2->v[j] = a;
			}
		}
		}
	return p2;	
		
}


