#include<stdio.h>
#include<stdlib.h>



int somavetor(int n, int *vet)
{
	int soma;
	for(int i = 0; i < n; i++)
	{
		soma += *(vet + i);
	}
	
	return soma;	
}

int main()
{
	int casas;
	printf("Digite o numero de casas: ");
	scanf("%d", &casas);
	
	int vet[casas];
	
	for(int i = 0; i < casas; i++)
	{
		printf("Digite o %d° elemento: ", i+1);
		scanf("%d", vet+i);
	}
	
	printf("O somatorio eh %d", somavetor(casas, vet));
}
