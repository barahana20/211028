#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comp_same(FILE* in1, FILE* in2);

int main()
{
	FILE* in1, *in2;
	in1 = fopen("in1.txt", "r");
	in2 = fopen("in2.txt", "r");
	comp_same(in1, in2);
	

}


void comp_same(FILE* in1, FILE* in2)
{
	int in1_size;
	int in2_size;
	fscanf(in1, "%d", &in1_size);
	fscanf(in2, "%d", &in2_size);

	int* in1_arr;
	int* in2_arr;
	in1_arr = (int*)malloc(sizeof(*in1_arr) * in1_size);
	in2_arr = (int*)malloc(sizeof(*in2_arr) * in2_size);
	int insert_num;
	for (int i = 0; i < in1_size; i++)
	{
		fscanf(in1, "%d", &insert_num);
		in1_arr[i] = insert_num;
	}
	for (int i = 0; i < in2_size; i++)
	{
		fscanf(in2, "%d", &insert_num);
		in2_arr[i] = insert_num;
	}
	int result_size = in1_size > in2_size ? in1_size : in2_size;
	int *result;
	result = (int*)malloc(sizeof(*result) * result_size);
	int count = 0;
	for (int i = 0; i < in1_size; i++)
	{
		for (int j = 0; j < in2_size; j++)
		{
			if (in1_arr[i] == in2_arr[j])
				result[count++] = in1_arr[i];
		}
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d ", result[i]);
	}
}