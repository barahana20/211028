#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
//#define MALLOC(p,s) if(!((p)=malloc(s))){fprintf(stderr, "insufficient memory");exit(1);}
typedef struct{
    int key;
}element;

element* stack;
//MALLOC(stack, sizeof(*stack));
int capacity = 1;
int top = -1;

void stackFull() {
    stack = realloc(stack, 2 * capacity * sizeof(*stack));
    capacity *= 2;
    printf("    doubling: %d\n", capacity);
}
void stackEmpty() {
    fprintf(stderr, "Stack is empty: cannot POP!\n");
    exit(1);
}
void push(element item) {
    if (top >= capacity-1)
    {
        stackFull();
    }
    else {
        printf("\n");

    }
    stack[++top] = item;
    
}

element pop() {
    if (top == -1) {
        stackEmpty();
    }
    return stack[top--];
}

int main()
{
    stack = (element*)malloc(sizeof(element));
    element item;
    FILE* a_pfile;
    a_pfile = fopen("in.txt", "r");
    if (a_pfile == NULL)
        printf("error");
    
    char char_temp;
    int int_temp;
    while (1)
    {
        
        int error_int = fscanf(a_pfile, "%c", &char_temp);
        if (feof(a_pfile))
            break;
        if (char_temp == 'I')
        {
            fscanf(a_pfile, "%c", &char_temp);
            fscanf(a_pfile, "%d", &int_temp);
            item.key = int_temp;
            
            printf("push item : %d", item.key);
            push(item);
            //printf("\ncapacity : %d\n", capacity);
            for (int j = 0; j <= top; j++)
                printf("[ %d]", stack[j].key);
            printf("\n");
        }
        else if (char_temp == 'D')
        {
            pop();
            printf("pop\n");
            for (int j = 0; j <= top; j++)
                printf("[ %d]", stack[j].key);
            printf("\n");
        }

    }

    
}