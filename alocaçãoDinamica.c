#include <stdio.h>
#include<stdlib.h>

int somatorio(int numeroLinhas, int mat[][2])
{
	int soma;
	
	for(int i = 0; i < numeroLinhas; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			soma += mat[i][j];
		}
	}
	
	return soma;
}

int main(void)
{
	int linhas;
	printf("Numero de linhas: ");
	scanf("%d",&linhas);
	
	int mat[linhas][2];
	for(int i = 0; i < linhas; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			//printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
			printf("Insira o elemento da linha %d e coluna %d: ", (i), (j));
			//int a;
			scanf("%d", mat[i][j]);
			//printf("a = %d\n", a);
			//mat[i][j] = a;
			printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
		}
	}
	printf("A soma eh: %d",somatorio(linhas, mat));
	free(mat);
	return 0;
}
