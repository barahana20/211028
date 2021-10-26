#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STR_SIZE 100
int compare(int a, int b)    // 오름차순 비교 함수 구현
{
	if (a < b)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (a > b)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int binsearch(int list[], int searchnum, int left, int right)
{

	int middle;
	while (left <= right) {
		middle = (left + right) / 2;

		switch (compare(list[middle], searchnum)) {
			case 0:
				return middle;
			case -1: 
				left = middle + 1;
				break;
			case 1: 
				right = middle - 1;
		}
	}
	return -1;
}


int rec_binsearch(int list[], int searchnum, int left, int right)
{

	int middle;
	while (left <= right) {
		middle = (left + right) / 2;

		switch (compare(list[middle], searchnum)) {
		case 0:
			return middle;
		case -1:
			return rec_binsearch(list, searchnum, middle + 1, right);
		case 1:
			return rec_binsearch(list, searchnum, left, middle - 1);
		}
	}
	return -1;
}

int main()
{
	FILE* pfile;
	char str_read[MAX_STR_SIZE];
	int list[100];
	int c = 0;
	pfile = fopen("C:\\Users\\barah\\Desktop\\in.txt", "r");
	if (pfile == NULL)
		printf("error");
	while (fscanf(pfile, "%d", &list[c]) != -1)
		c++;

	int n = c;
	int num=0;
	while (1)
	{
		printf("Input number: ");
		scanf("%d", &num);
		if (num == -1)
			break;
		int result = binsearch(list, num, 0, n - 1);
		if (result == -1)
			printf("iterative binary search: 없음\n");
		else
			printf("iterative binary search: 있음\n");
		int rec_result = rec_binsearch(list, num, 0, n - 1);
		if (result == -1)
			printf("recursive binary search: 없음\n");
		else
			printf("recursive binary search: 있음\n");
		//printf("%d", result);
	}
	printf("Exit");
	return 0;
}