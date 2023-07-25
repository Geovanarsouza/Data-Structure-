#include <stdio.h>
#include "lista.h"
 int main (void)
 {
 	Lista* l = criarLista();
 	l = insereElementoLista(l,10);
 	l = insereElementoLista(l,20);
 	l = insereElementoLista(l,30);
 	l = insereElementoLista(l,40);
 	l = insereElementoLista(l,50);
 	imprimirLista(l);
 	printf("after");
 	l = insere_fim_lista(l,80);
 	imprimirLista(l);
 	return 0;
 }
