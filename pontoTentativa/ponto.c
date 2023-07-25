#include "ponto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ponto
{
	float x;
	float y;
};

Ponto* criarPonto(float x, float y)
{
	Ponto *ponto = (Ponto*)malloc(sizeof(Ponto));
	if(ponto == NULL)
	{
		printf("Memória Insuficiente");
		exit(1);
	}
	ponto->x = x;
	ponto->y = y;
	return ponto;
}

void liberarMemoria(Ponto *ponto)
{
	free(ponto);
}

void atribuirNovosValores(Ponto *ponto, float x, float y)
{
	ponto->x = x;
	ponto->y = y;
}

float calcularDistancia(Ponto *ponto1, Ponto *ponto2)
{
	float x = ponto1->x - ponto2->x;
	float y = ponto2->x - ponto2->y;
	return sqrt(x*x+y*y);
}
