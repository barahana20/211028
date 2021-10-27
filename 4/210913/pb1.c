#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STR_SIZE 100


int main()
{
	FILE* in1_pfile;
	FILE* in2_pfile;
	char str_read[MAX_STR_SIZE];
	

	int in1_c = 0;
	in1_pfile = fopen("in1.txt", "r");
	in2_pfile = fopen("in2.txt", "r");
	int in1_range[10];
	fscanf(in1_pfile, "%d", in1_range);
	int in2_range[10];
	fscanf(in2_pfile, "%d", in2_range);
	int *in1_list;
	int *in2_list;
	in1_list = (int*)malloc(in1_range[0] * sizeof(int));
	in2_list = (int*)malloc(in2_range[0] * sizeof(int));
	if (in1_pfile == NULL)
		printf("error");
	while (fscanf(in1_pfile, "%d", &in1_list[in1_c]) != -1)
		in1_c++;

	int in2_c = 0;
	while (fscanf(in2_pfile, "%d", &in2_list[in2_c]) != -1)
		in2_c++;

	int in1_n = in1_c;
	int in2_n = in2_c;
	int num = 0;

	for (int i = 1; i < in1_n; i++)
	{
		for (int j = 1; j < in2_n; j++)
		{
			if (in1_list[i] == in2_list[j])
				printf("%d ", in1_list[i]);
		}
	}

}