#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
 Fila* f1 = fila_cria();
 fila_insere(f1,10);
 fila_insere(f1,12);
 fila_insere(f1,13);
 fila_insere(f1,14);
 fila_insere(f1,15);
 printf("%d",fila_retira_par(f1));
	return 0;
}
