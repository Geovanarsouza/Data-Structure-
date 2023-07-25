#include <stdio.h>

struct Ponto
{
	float x;
	float y;
};

int main(void)
{
	struct Ponto p1;
	printf("Insira as coordenadas x e y do ponto: ");
	scanf("%f %f",&p1.x,&p1.y);
	printf("x: %.1f\ny: %.1f",p1.x,p1.y);
}
