#include <stdio.h>

int somatorio(int n,int m,int **matriz)
{
	int soma;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			soma += matriz[i][j];
		}
	}
	
	return soma;
}

int main(void)
{
	int n,m;
	printf("linhas: ");
	scanf("%d",&n);
	printf("colunas: ");
	scanf("%d", &m);
	
	//vetor base
	int **matriz = (int**)malloc(n*sizeof(int*)); 
	for(int i = 0; i < n; i++)
	{
		//vetores linhas
		matriz[i] = (int*)malloc(m*sizeof(int));
	}
	if(matriz == NULL)
	{
		printf("espaço insuficiente");
		exit(1);
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("linha %d coluna %d",(i+1),(j+1));
			int a ;
			scanf("%d",&a);
			matriz[i][j]=a;
		}
	}
	printf("soma: %d",somatorio(n,m,matriz));
	
	for(int i = 0; i < m; i++)
	{
		free(matriz[i]);
	}
	
	free(matriz);
}
