#include <stdio.h>

struct Ponto
{
	float x;
	float y;
};

void captura(struct Ponto *pp)
{
	printf("Informe as coordenadas X e Y do ponto: ");
	scanf("%f %f",&((*pp).x), &((*pp).y));
	/*scanf("%f %f",&(pp->x), &(pp->y));
	*
	*/
}

void imprime(struct Ponto *pp)
{
	printf("X:%.1f\n",((*pp).x));
	printf("Y:%.1f",((*pp).y));
	/*
	*printf("X:%.1f\n",(pp->x));
	printf("Y:%.1f",(y));
	*/
}

int main(void)
{
	struct Ponto p;
	captura(&p);
	imprime(&p);
	return 0;
}
