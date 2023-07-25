#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct lista{
 int info;
 Lista *prox; 
};

struct fila{
 Lista *ini;
 Lista *fim;
}; 

Fila* fila_cria(void){
 Fila *f = (Fila*)malloc(sizeof(Fila));
 if(f==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 f->ini = NULL;
 f->fim = NULL;
 return f;
}

void fila_insere(Fila *f, int info){
 Lista *l = (Lista*)malloc(sizeof(Lista));
 if(l==NULL){
 printf("Memoria insuficiente!!!\n");
 exit(1);
 }
 l->info = info;
 l->prox = NULL;
 if(!fila_vazia(f))
 f->fim->prox = l;
 else
 f->ini = l;
 f->fim = l;
}

int fila_vazia(Fila *f){
 return f->ini==NULL;
}
int fila_remove(Fila *f){
 Lista *l; int a;
 if(fila_vazia(f)){
 printf("Fila Vazia!!!\n");
 exit(1);
 }
 a = f->ini->info;
 l = f->ini;
 f->ini = f->ini->prox;
 free(l);
 if(fila_vazia(f))
 f->fim = NULL;
 return a;
}

/*Função que imprime os elementos de uma fila.*/
void fila_imprime(Fila *f){
 Lista *lAux = f->ini;
 while(lAux!=NULL){
 printf("%d\n",lAux->info);
 lAux = lAux->prox;
 }
}

/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila *f){
 Lista* l = f->ini;
 Lista* lAux;
 while(l!=NULL){
 lAux = l->prox;
 free(l);
 l = lAux;
 }
 free(f);
}

int fila_retira_par(Fila *f)
{
	if(f->ini == NULL)
	{
		printf("fila vazia!!!\n");
		exit(1);
	}
	else if((f->ini->info) % 2 == 0)
	{
		int a = f->ini->info;
		Lista *ln = f->ini;
		f->ini = f->ini->prox;
		free(ln);
		if(f->ini == NULL)
		{
			f->ini = NULL;
		}
		return a;
	}
	else
	{
		printf("O elemento não é par");
		exit(2);
	}
}



