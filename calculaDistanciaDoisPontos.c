#include <stdio.h>
#include <math.h>

typedef struct ponto
{
	float x;
	float y;
}Ponto;

void captura(Ponto *ponto)
{
	printf("Informe os valores X e Y: \n");
	scanf("%f %f", &(ponto->x), &(ponto->y));
}

float calculaDistancia(Ponto *p1, Ponto *p2)
{
	return sqrt(((p1->x)-(p2->x))*((p1->x)-(p2->x))+((p1->y)-(p2->y))*((p1->y)-(p2->y)));
}

int main(void)
{
	Ponto p1,p2;
	captura(&p1);
	captura(&p2);
	printf("Distancia: %.1f",calculaDistancia(&p1,&p2));
}
