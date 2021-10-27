#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

int compare(int a, int b);
void attach(int coefficient, int exponent);
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD);


typedef struct {
	int coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;


int compare(int a, int b)    // 오름차순 비교 함수 구현
{
	if (a < b)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (a > b)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}
void attach(int coefficient, int exponent)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail].expon = exponent;
	avail++;
}
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
{
	int coefficient;
	*startD = avail;
	while (startA <= finishA && startB <= finishB)
	{
		switch (compare(terms[startA].expon, terms[startB].expon)) {
		case -1:
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
			break;
		}
	}
	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishD = avail - 1;

}


int main()
{
	int startA, finishA;
	int startB, finishB;
	int startD, finishD;
	FILE* a_pfile;
	FILE* b_pfile;
	char str_read[100];
	int a_c = 0;
	a_pfile = fopen("C:\\Users\\barah\\Desktop\\a2.txt", "r");
	b_pfile = fopen("C:\\Users\\barah\\Desktop\\b2.txt", "r");
	int a_range[10] = { 0 };
	int b_range[10] = { 0 };
	int a_list[101];
	int b_list[101];
	if (a_pfile == NULL)
		printf("error");
	while (fscanf(a_pfile, "%d", &a_list[a_c]) != -1)
		a_c++;

	int b_c = 0;
	while (fscanf(b_pfile, "%d", &b_list[b_c]) != -1)
		b_c++;

	int a_n = a_c;
	int b_n = b_c;
	int num = 0;
	int i = 0;
	int terms_count = 0;
	int termsA_c = 0;
	int termsB_c = 0;
	startA = 0;
	while (i < a_n)
	{
		terms[terms_count].coef = a_list[i];
		terms[terms_count].expon = a_list[i + 1];
		i++;
		i++;
		terms_count++;
		termsA_c++;
	}
	finishA = terms_count - 1;
	startB = finishA + 1;
	int j = 0;
	while (j < b_n)
	{
		terms[terms_count].coef = b_list[j];
		terms[terms_count].expon = b_list[j + 1];
		j++;
		j++;
		terms_count++;
		termsB_c++;
	}
	finishB = terms_count - 1;
	avail = terms_count;
	padd(startA, finishA, startB, finishB, &startD, &finishD);

	printf("A(x) : ");
	for (int i = startA; i < finishA + 1; i++)
	{
		printf("%d^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%d^%d", terms[finishA].coef, terms[finishA].expon);
	printf("\n");
	printf("B(x) : ");
	for (int i = startB; i < finishB; i++)
	{
		printf("%d^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%d^%d", terms[finishB].coef, terms[finishB].expon);
	printf("\n\n");
	printf("C(x) : ");
	for (int i = startD; i < finishD; i++)
	{
		printf("%d^%d + ", terms[i].coef, terms[i].expon);
	}
	if (startD < finishD)
		printf("%d^%d", terms[finishD].coef, terms[finishD].expon);
	else
		printf("0\n");
}