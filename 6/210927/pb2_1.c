#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAT_SIZE 100
struct matrix {
	int row;
	int col;
	int non;
};
typedef struct matrix MAT;

int** malloc_func(int start_row, int start_col)
{
	int** arr = malloc(sizeof(int*) * start_row);
	for (int i = 0; i < start_row; i++)
		arr[i] = malloc(sizeof(int) * start_col);
	for (int i = 0; i < start_row; i++)
		for (int j = 0; j < start_col; j++)
			arr[i][j] = 0;
	return arr;
}

int main()
{
	FILE* m1, * m2;
	m1 = fopen("m1.txt", "r");
	m2 = fopen("m2.txt", "r");
	MAT m1_mat, m2_mat;
	int m1_start_row, m1_start_col, m1_start_non;
	int m2_start_row, m2_start_col, m2_start_non;

	fscanf(m1, "%d", &m1_start_row);
	fscanf(m1, "%d", &m1_start_col);
	fscanf(m1, "%d", &m1_start_non);
	int** m1_arr = malloc_func(m1_start_row, m1_start_col);
	int** m1_trans_arr = malloc_func(m1_start_row, m1_start_col);
	for (int i = 0; i < m1_start_row; i++)
	{
		for (int j = 0; j < m1_start_col; j++)
		{
			m1_arr[i][j] = 0;
			m1_trans_arr[i][j] = 0;
		}
	}
	fscanf(m2, "%d", &m2_start_row);
	fscanf(m2, "%d", &m2_start_col);
	fscanf(m2, "%d", &m2_start_non);
	int** m2_arr = malloc_func(m2_start_row, m2_start_col);
	int** m2_trans_arr = malloc_func(m2_start_row, m2_start_col);
	for (int i = 0; i < m2_start_row; i++)
	{
		for (int j = 0; j < m2_start_col; j++)
		{
			m2_arr[i][j] = 0;
			m2_trans_arr[i][j] = 0;
		}
	}
	while (1)
	{
		if (fscanf(m1, "%d", &m1_mat.row) == -1 || fscanf(m1, "%d", &m1_mat.col) == -1 || fscanf(m1, "%d", &m1_mat.non) == -1)
			break;
		m1_arr[m1_mat.row][m1_mat.col] = m1_mat.non;
		m1_trans_arr[m1_mat.col][m1_mat.row] = m1_mat.non;
	}
	printf("Before Transposing\n");
	for (int i = 0; i < m1_start_row; i++)
	{
		for (int j = 0; j < m1_start_col; j++)
			printf("%3d", m1_arr[i][j]);
		printf("\n");
	}
	printf("After Transposing\n");
	for (int i = 0; i < m1_start_row; i++)
	{
		for (int j = 0; j < m1_start_col; j++)
			printf("%3d", m1_trans_arr[i][j]);
		printf("\n");
	}
		
}