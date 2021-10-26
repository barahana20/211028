#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int row = 0;
	int col = 0;
	printf("row size: ");
	scanf("%d", &row);

	printf("col size: ");
	scanf("%d", &col);
	arr = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
		arr[i] = (int*)malloc(sizeof(int) * col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = i * i + j * j;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < row; i++)
	{
		printf("free arr[%d].\n", i);
		free(arr[i]);
	}
	printf("free arr.");
	free(arr);
}