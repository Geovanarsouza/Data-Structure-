#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct lista
{
	int info;
	Lista* prox;
};

struct pilha
{
	Lista* prim;
};

Pilha* pilha_cria(void){
 Pilha *p = (Pilha*)malloc(sizeof(Pilha));
 if(p==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 p->prim = NULL;
 return p;
}

/*Função que adiciona um elemento no topo de uma pilha.*/
void pilha_push(Pilha *p, int info){
 Lista *l = (Lista*)malloc(sizeof(Lista));
 if(l==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 l->info = info;
 l->prox = p->prim;
 p->prim = l;
}

/*Testa se uma pilha é vazia.*/
int pilha_vazia(Pilha *p){
 return p->prim==NULL;
}

/*Função que remove um elemento do topo de uma pilha.*/
int pilha_pop(Pilha *p){
 int a;
 Lista *l;
 if(pilha_vazia(p)){
 printf("Pilha Vazia!!!\n");
 exit(1); 
 }
 l = p->prim;
 a = l->info;
 p->prim = l->prox;
 free(l);
 return a;
}

/*Função que imprime os elementos de uma pilha.*/
void pilha_imprime(Pilha *p){
 Lista *lAux = p->prim;
 while(lAux!=NULL){
 printf("%d\n",lAux->info);
 lAux = lAux->prox;
 }
}

/*Libera o espaço alocado para uma pilha.*/
void pilha_libera(Pilha *p){
 Lista* l = p->prim;
 Lista* lAux;
 while(l!=NULL){
 lAux = l->prox;
 free(l);
 l = lAux;
 }
 free(p);
}

/*insere um elemento no topo da pilha apenas se ele foi maior que o topo*/
/*void pilha_push_maior(Pilha *p, int info)
{
	if((p->prim->info) < info || (p->prim) == NULL)
	{
		Lista *ln = (Lista*)malloc(sizeof(Lista));
		if(ln == NULL)
		{
			printf("Memória Insuficiente!!!\n");
			exit(1);
		}
		ln->info = info;
		ln->prox = p->prim;
		p->prim = ln;
	}
}*/
