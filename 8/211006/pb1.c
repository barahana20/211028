#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
int top = -1;
typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
}ST;
typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;
precedence point(char* point) {
    switch (*point) {
    case '(': return lparen;
    case ')': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '*': return times;
    case '/': return divide;
    case '%': return mod;
    case '\\': return eos;
    default: return operand;
    }
}
int change_value(char* num, int* index) {
    int value;
    char temp[100];
    int i, count;
    for (i = 0; num[i] != ' '; i++)
        temp[i] = num[i];
    temp[i] = '\0';
    value = atoi(temp);
    count = *index;
    *index = count + i;
    return value;
}
void init(ST* s) {
    s->top = -1;
}

int stack_empty(ST* s) {
    return (s->top == -1);
}
int is_full() {    
    if (top >= MAX_STACK_SIZE - 1) {   
        printf("Error : Stack is Full. \n");  
        return 1;  
    }
    return 0;   
}

void push(ST* s, int item) {
    if (is_full(s)) {
        printf("스택 가득참\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
int empty_find(ST* s) {
    if (stack_empty(s)) {
        printf("비어 있음\n");
        exit(1);
    }
    else return s->stack[s->top];
}

int pop(ST* s) {
    if (stack_empty(s)) {
        printf("비어 있음\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

int prec(char op) {
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': case '%': return 2;
    }
    return -1;
}

void infix_to_postfix(char* infix, char* postfix) {
    ST s;
    init(&s);
    while (*infix != '\0') {
        if (*infix == '(') {
            push(&s, *infix);
            infix++;
        }
        else if (*infix == ')') {
            while (empty_find(&s) != '('){
                *postfix++ = pop(&s);
                *postfix++ = ' ';
            }
            pop(&s);
            infix++;
        }
        else if (*infix == '+' || *infix == '-' || *infix == '*' || *infix == '/' || *infix == '%') {
            while (!stack_empty(&s) && (prec(*infix) <= prec(empty_find(&s)))) {
                *postfix++ = pop(&s);
                *postfix++ = ' ';
            }
            push(&s, *infix);
            infix++;
        }
        else if (*infix >= '0' && *infix <= '9') {
            do {
                *postfix++ = *infix++;
            } while ((*infix >= '0' && *infix <= '9'));
            *postfix++ = ' ';
        }
        else
            infix++;
    }
    while (!stack_empty(&s)) {
        *postfix++ = pop(&s);
        *postfix++ = ' ';
    }
    postfix--;
    *postfix = '\0';
}
int eval(char* postfix)
{
    precedence temp;
    int value, op1, op2;
    int i;
    ST s;
    init(&s);
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == ' ')
            i++;
        temp = point(&postfix[i]);
        if (temp == operand) {
            value = change_value(&postfix[i], &i);
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (temp) {
                case plus: push(&s, op1 + op2); break;
                case minus: push(&s, op1 - op2); break;
                case times: push(&s, op1 * op2); break;
                case divide: push(&s, op1 / op2); break;
                case mod: push(&s, op1 % op2); break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char line[MAX_STACK_SIZE];
    char* infix[MAX_STACK_SIZE];
    char* pStr;
    int count = 0;
    int len = 0;
    FILE* in = fopen("index.txt", "r");
    while (!feof(in)) {
        pStr = fgets(line, MAX_STACK_SIZE, in);
        len = strlen(pStr) + 1;
        infix[count] = (char*)malloc(sizeof(char) * len);
        strcpy(infix[count], pStr);
        count++;
    }
    fclose(in);
    int j = 0;
    for (int i = 0; i < count; i++)
    {
        j = 0;
        printf("Infix: ");
        while(infix[i][j] != '\0')
            printf("%c", infix[i][j++]);
        
        char postfix[MAX_STACK_SIZE];
        infix_to_postfix(infix[i], postfix);
        if (i == count - 1)
            printf("\n");
        printf("Postfix: ");
        printf("%s", postfix);
         
            
        printf("\n");
        
        printf("Evaluation: %d\n\n", eval(postfix));
    }
    
}