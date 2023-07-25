#include <stdio.h>
#include "ponto.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Ponto *ponto1 = criarPonto(2.0,3.0);
	Ponto *ponto2 = criarPonto(3.0,2.0);
	printf("%f",ponto1->x);
	float d = calcularDistancia(ponto1, ponto2);
	printf("%f",d);
	liberarMemoria(ponto1);
	liberarMemoria(ponto2);
	return 0;
}
