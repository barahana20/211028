#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPR_SIZE 100
#define MAX_STACK_SIZE 100

int top = 0;
typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
char eval_expr[MAX_EXPR_SIZE];
static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

void postfix(void);
void push(int item);
int eval(void);
int pop(void);
precedence get_token(char expr[], char* symbol, int* n);
char printToken(int s);
void eval_expr_gen(int item);
int eval_expr_count = 0;

void eval_expr_gen(int item)
{
	switch (item)
	{
	case lparen: eval_expr[eval_expr_count++] = '('; break;
	case rparen: eval_expr[eval_expr_count++] = ')'; break;
	case plus: eval_expr[eval_expr_count++] = '+'; break;
	case minus: eval_expr[eval_expr_count++] = '-'; break;
	case times: eval_expr[eval_expr_count++] = '*'; break;
	case divide: eval_expr[eval_expr_count++] = '/'; break;
	case mod: eval_expr[eval_expr_count++] = '%'; break;
	case eos: eval_expr[eval_expr_count++] = '\0'; break;
	default: eval_expr[eval_expr_count++] = 'E'; break;
	}
}
void postfix(void)
{
	char symbol;
	precedence token;
	int n = 0;
	stack[0] = eos;
	int pop_item;
	for (token = get_token(expr,&symbol, &n); token != eos; token = get_token(expr, &symbol, &n))
	{
		if (token == operand)
		{
			printf("%c", symbol);
			eval_expr[eval_expr_count++] = symbol;
		}
		else if (token == rparen)
		{
			while (stack[top] != lparen)
			{
				pop_item = pop();
				printToken(pop_item);
				eval_expr_gen(pop_item);
			}
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token])
			{
				pop_item = pop();
				printToken(pop_item);
				eval_expr_gen(pop_item);
			}
			push(token);
		}
	}
	while ((token = pop()) != eos)
	{
		printToken(token);
		eval_expr_gen(token);
	}
	printf("\n");
}
precedence get_token(char expr[], char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;	
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '\0': case '\n': return eos;
	default: return operand;
	}
}
char printToken(int s)
{
	switch (s)
	{
	case lparen: printf("%c", '('); break;
	case rparen: printf("%c", ')'); break;
	case plus: printf("%c", '+'); break;
	case minus: printf("%c", '-'); break;
	case times: printf("%c", '*'); break;
	case divide: printf("%c", '/'); break;
	case mod: printf("%c", '%'); break;
	case eos: printf("%c", '\0'); break;
	default: printf("%c", 'E'); break;
	}
}
void push(int item)
{
	if (top >= MAX_STACK_SIZE-2)
	{
		fprintf(stdout, "push error");
		return;
	}
	stack[++top] = item;
}
int pop(void)
{
	if (top <= -1)
		return;
	return stack[top--];
}
int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	token = get_token(eval_expr, &symbol, &n);
	while (token != eos)
	{
		if (token == operand)
			push(symbol - '0');
		else
		{
			if (top >= 1)
			{
				op2 = pop();
				op1 = pop();
				switch (token)
				{
				case plus:
					push(op1 + op2); break;
				case minus:
					push(op1 - op2); break;
				case times:
					push(op1 * op2); break;
				case divide:
					push(op1 / op2); break;
				case mod:
					push(op1 % op2); break;
				}
			}
			
		}
		token = get_token(eval_expr, &symbol, &n);
	}
	return pop();
}

int main()
{
	FILE* fp = fopen("index.txt", "r");
	char test_char = '1';
	int count = 0;
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			char strTemp[255];
			char* pStr;
			pStr = fgets(strTemp, sizeof(strTemp), fp);
			strcpy(expr, pStr);
			printf("%d ", strlen(pStr));
			
			for (int i = 0; i < strlen(pStr); i++)
				printf("%c", expr[i]);

			expr[strlen(pStr)+1] = '\0';
			printf("\n");
			
			printf("Infix: ");

			printf("%s", expr);
			printf("\nPostfix: ");
			postfix();
			printf("\nEvaluation:%d\n\n", eval());
			
		}
		fclose(fp);
	}
	exit(1);
	/*
	while (1)
	{
		if (fscanf(fp, "%c", &test_char) == EOF)
			break;
		expr[count++] = test_char;
		count = 0;
		while (1)
		{
			
			if (fscanf(fp, "%c", &test_char) == EOF)
				break;
			expr[count++] = test_char;
			//expr[count] = '\0';

			printf("Infix: ");
			for (int i = 0; i < count; i++)
				printf("%c", expr[i]);
			printf("\nPostfix: ");
			postfix();
			printf("\nEvaluation:%d\n\n", eval());

			test_char = '1';
			top = 0;
		}
		
		
		
	}
	*/
	/*
	eval();
	printf("\n\n");
	for (int i = 0; i <= top; i++)
		printf("%d ", stack[i]);
		*/
	return 0;
}