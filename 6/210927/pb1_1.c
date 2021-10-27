#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PP 100
#define SWAP(x,y) ((temp) = (x), (x) = (y), (y) = (temp))

struct people
{
	int num;
	char name[10];
};
typedef struct people PP;
int main()
{
	FILE* in, * add, *out;
	in = fopen("in.txt", "r");
	add = fopen("add.txt", "r");
	out = fopen("out.txt", "w");
	PP in_PP[MAX_PP], add_PP[MAX_PP], out_PP[MAX_PP];
	int in_max = 0, add_max = 0, out_max = 0;

	while (1)
	{
		if (fscanf(in, "%d", &in_PP[in_max].num) == -1 || fscanf(in, "%s", in_PP[in_max++].name) == -1)
			break;
	}
	while (1)
	{
		if (fscanf(add, "%d", &add_PP[add_max].num) == -1 || fscanf(add, "%s", add_PP[add_max++].name) == -1)
			break;
	}
	for (int i = 0; i < in_max; i++)
	{
		out_PP[i].num = in_PP[i].num;
		strcpy(out_PP[i].name, in_PP[i].name);
	}
	for (int i = in_max; i < in_max + add_max; i++)
	{
		out_PP[i].num = add_PP[i-in_max].num;
		strcpy(out_PP[i].name, add_PP[i-in_max].name);
	}

	out_max = in_max + add_max - 1;
	for (int i = out_max - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (out_PP[j].num > out_PP[j + 1].num)
			{
				int temp;
				SWAP(out_PP[j].num, out_PP[j + 1].num);
				char temp1[10];
				strcpy(temp1, out_PP[j].name);
				strcpy(out_PP[j].name, out_PP[j + 1].name);
				strcpy(out_PP[j + 1].name, temp1);
			}
		}
	}
	for (int i = 0; i < out_max; i++)
	{
		if (i < out_max - 1)
		{
			if (out_PP[i].num == out_PP[i + 1].num)
			{
				printf("%2d: %5s\n", out_PP[i].num, "ERROR");
				fprintf(out, "%2d %5s\n", out_PP[i].num, "ERROR");
				i++;
				continue;
			}
				
		}
		printf("%2d, %5s\n", out_PP[i].num, out_PP[i].name);
		fprintf(out, "%2d %5s\n", out_PP[i].num, out_PP[i].name);
	}
		
	
		
}