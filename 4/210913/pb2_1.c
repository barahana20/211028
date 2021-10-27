#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row_size, col_size;
	printf("row size:");
	scanf("%d", &row_size);
	printf("col size:");
	scanf("%d", &col_size);
	int** a;
	a = malloc(sizeof(int*) * row_size);
	for (int i = 0; i < row_size; i++)
		a[i] = malloc(sizeof(int) * col_size);
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			a[i][j] = i*i + j*j;
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < row_size; i++)
	{
		free(a[i]);
		printf("free arr[%d].\n", i);
	}
	printf("free arr.");
}