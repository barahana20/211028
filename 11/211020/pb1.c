#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0:1)

typedef struct polyNode* polyPointer;
typedef struct polyNode
{
	int coef;
	int expon;
	polyPointer link;
};

void input(polyPointer* a, char* filename);
polyPointer padd(polyPointer a, polyPointer b);
void attach(int, int, polyPointer* ptr);
void printList(polyPointer head);
void erase(polyPointer);

void main()
{
	polyPointer a, b, result, head;
	a = malloc(sizeof(*a));
	b = malloc(sizeof(*b));
	head = malloc(sizeof(*head));
	a = NULL;
	b = NULL;
	head->link = a;
	char* poly1 = "poly1.txt";
	char* poly2 = "poly2.txt";
	input(&a, poly1);
	input(&b, poly2);
	
	result = padd(a, b);
	printf("%10s", "poly A:");
	printList(a);
	printf("%10s", "poly B:");
	printList(b);
	printf("%10s", "poly (A+B):");
	printList(result);
	erase(&a);
	erase(&b);
	erase(&result);
	printf("\n»èÁ¦>>\n");
	printf("%10s", "poly A:");
	printList(a);
	printf("%10s", "poly B:");
	printList(b);
	printf("%10s", "poly (A+B):");
	printList(result);
}
void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr)
	{
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}
void printList(polyPointer r)
{
	if (r)
	{
		while (r)
		{
			printf("[%d,%d] ", r->coef, r->expon);
			r = r->link;
		}
		
	}
	else
	{
		printf("empty list");
	}
	printf("\n");
}
void input(polyPointer* a, char* filename)
{
	polyPointer temp_ab, rear_ab;
	rear_ab = *a;


	FILE* fp = fopen(filename, "r");
	if (!fp)
	{
		printf("error");
		exit(1);
	}
	char line[100];
	fgets(line, 100, fp);
	char* ptr = strtok(line, " ");
	while (ptr != NULL)
	{
		temp_ab = malloc(sizeof(*temp_ab));
		temp_ab->coef = atoi(ptr);
		ptr = strtok(NULL, " ");
		temp_ab->expon = atoi(ptr);
		ptr = strtok(NULL, " ");
		if (*a)
			rear_ab->link = temp_ab;
		else
			*a = temp_ab;
		rear_ab = temp_ab;
		temp_ab->link = NULL;

	}
}

polyPointer padd(polyPointer a, polyPointer b)
{
	int sum;
	polyPointer c, rear, temp;
	c = malloc(sizeof(*c));
	rear = malloc(sizeof(*rear));
	c = rear;
	while (a && b)
	{
		switch (COMPARE(a->expon, b->expon))
		{
		case -1:
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum)
				attach(sum, a->expon, &rear);
			a = a->link;
			b = b->link;
			break;
		case 1:
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}
	for (; a; a = a->link)
		attach(a->coef, a->expon, &rear);
	for (; b; b = b->link)
		attach(b->coef, b->expon, &rear);
	temp = c;
	c = c->link;
	free(temp);
	return c;

}

void attach(int coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	temp = malloc(sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	temp->link = NULL;
	(*ptr)->link = temp;
	*ptr = temp;
}

