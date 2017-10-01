#include<stdio.h>
#include<stdlib.h>



int main(void)
{
	int x,y,z,i,j,k;
	int ***matrix;
	

	printf("Give the dimensions (X Y Z) of the array: ");

	scanf("%d%d%d", &x, &y, &z);
	
	
	matrix = (int***)malloc(x * sizeof(int**));
	
	if (matrix == NULL)
	{
		printf("ERROR! Memory not allocated!!\n");
		exit(0);
	}


	
	for (i = 0; i < x; i++)
	{
		matrix[i] = (int**)malloc(y * sizeof(int*));
		if (matrix[i] == NULL)
		{
			printf("ERROR! Memory not allocated!!\n");
			exit(0);
		}

		for (j = 0; j < y; j++)
		{
			matrix[i][j] = (int*)malloc(z * sizeof(int));
			if (matrix[i][j] == NULL)
			{
				printf("ERROR! Memory not allocated!!\n");
				exit(0);
			}

		}
	}

	
	 
	//here, the programma fills the cells of the array, with the apropriate value
	for (k = 0; k < z; k++)
	{
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				matrix[i][j][k] = (100 * (i+1)) + (10 * (j+1)) + (k+1);
			}
		}
	}

	//here the programm prints the arrays 
	for (k = 0; k < z; k++)
	{
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				printf("%d ", matrix[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
	
	
	
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			free(matrix[i][j]);	
		}
		free(matrix[i]);	
	}
	free(matrix);
	
	
	printf("The programm terminated correctly\n");



	return 0;
}

