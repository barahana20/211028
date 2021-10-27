#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	int item;
}ELEMENT;

int capacity = 1;
int top = -1;

void stack_Full(ELEMENT* stack);
void stack_Empty(void);
int pop(ELEMENT*);
void push(ELEMENT*,int);
void printStack(ELEMENT* stack);

void stack_Full(ELEMENT* stack)
{
	printf("   doubling: %d", capacity * 2);
	realloc(stack, sizeof(*stack)*(capacity * 2));
	capacity *= 2;
}
void push(ELEMENT* stack,int item)
{
	printf("push item: %d", item);
	if (top >= capacity-1)
		stack_Full(stack);
	printf("\n");
	stack[++top].item = item;
}
void stack_Empty(void)
{
	printf("stack empty: cannot POP!\n");
	exit(1);
}
int pop(ELEMENT* stack)
{
	if (top <= -1)
	{
		stack_Empty();
		return -1;
	}
	printf("pop\n");
	return stack[top--].item;
}
void printStack(ELEMENT* stack)
{
	for (int i = 0; i <= top; i++)
		printf("[%2d]", stack[i].item);
	printf("\n");
}
int main()
{
	ELEMENT* stack;
	stack = (ELEMENT*)malloc(sizeof(*stack)*capacity);
	FILE* fp = fopen("in1.txt", "r");
	char input_char[10];
	while (fscanf(fp, "%s", input_char) != -1)
	{
		if (input_char[0] == '|')
			continue;
		else if (input_char[0] == 'D')
		{
			pop(stack);
			printStack(stack);
		}
		else if (input_char[0] == ' ')
			continue;
		else
		{
			push(stack, atoi(input_char));
			printStack(stack);
		}
	}
	return 0;
}
