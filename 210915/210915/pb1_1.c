#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct POLYNOMIAL POLY;
struct POLYNOMIAL {
	int coef;
	int expon;
};

int compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}
int main()
{
	POLY a_poly[MAX_TERMS], b_poly[MAX_TERMS];
	FILE* a, * b;
	a = fopen("a2.txt", "r");
	b = fopen("b2.txt", "r");

	int a_max = 0, b_max = 0;
	int scanf_num;
	while(1)
	{
		if (fscanf(a, "%d", &scanf_num) == -1)
			break;
		a_poly[a_max].coef = scanf_num;
		fscanf(a, "%d", &scanf_num);
		a_poly[a_max++].expon = scanf_num;
		
	}
	while (1)
	{
		if (fscanf(b, "%d", &scanf_num) == -1)
			break;
		b_poly[b_max].coef = scanf_num;
		fscanf(b, "%d", &scanf_num);
		b_poly[b_max++].expon = scanf_num;
	}
	printf("A(x):");
	for (int i = 0; i < a_max; i++)
	{
		if (i == a_max - 1)
		{
			printf("%d^%d", a_poly[i].coef, a_poly[i].expon);
			break;
		}
		printf("%d^%d + ", a_poly[i].coef, a_poly[i].expon);	
	}
	printf("\nB(x):");
	for (int i = 0; i < b_max; i++)
	{
		if (i == b_max - 1)
		{
			printf("%d^%d", b_poly[i].coef, b_poly[i].expon);
			break;
		}
		printf("%d^%d + ", b_poly[i].coef, b_poly[i].expon);
	}
	printf("\n\n");
	POLY c_poly[MAX_TERMS];
	int count = 0;
	int start_a = 0, start_b = 0, start_c = 0;
	while (start_a <= a_max && start_b <= b_max)
	{
		switch (compare(a_poly[start_a].expon, b_poly[start_b].expon))
		{
		case 1:
			c_poly[start_c].coef = a_poly[start_a].coef;
			c_poly[start_c].expon = a_poly[start_a].expon;
			start_c++; start_a++;
			break;
		case 0:
			if (a_poly[start_a].coef + b_poly[start_b].coef == 0)
			{
				start_a++; start_b++; break;
			}
			c_poly[start_c].coef = a_poly[start_a].coef + b_poly[start_b].coef;
			c_poly[start_c].expon = a_poly[start_a].expon;
			start_a++; start_b++; start_c++; break;
		case -1:
			c_poly[start_c].coef = b_poly[start_b].coef;
			c_poly[start_c].expon = b_poly[start_b].expon;
			start_c++; start_b++; break;
		}
	}
	printf("C(x):");
	if (start_c == 1)
		printf("0");
	for (int i = 0; i < start_c-1; i++)
	{
		if (i == start_c - 2)
		{
			printf("%d^%d\n", c_poly[i].coef, c_poly[i].expon);
			break;
		}
			
		printf("%d^%d + ", c_poly[i].coef, c_poly[i].expon);
	}
	
}