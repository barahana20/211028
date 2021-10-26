#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
typedef struct NODE* listPointer;
struct NODE {   
    listPointer link;   
    int data;             
};

void insert(listPointer target, int data)    
{
    listPointer temp = malloc(sizeof(struct NODE));    
    temp->link = target->link;
    temp->data = data;

    target->link = temp;   
}

int main()
{
    listPointer first = malloc(sizeof(struct NODE));

    first->link = NULL;
    char line[100];
    FILE* fp = fopen("list.txt", "r");
    if (!fp)
    {
        printf("error");
        exit(1);
    }
    fgets(line, 100, fp);
    char* ptr = strtok(line, " ");
    while (ptr != NULL)
    {
        int input_num = atoi(ptr);
        if(input_num%2 == 0)
            insert(first, input_num);
        ptr = strtok(NULL, " ");
    }


    listPointer curr = first->link;  
    printf("Â¦¼ö ¸®½ºÆ®:\n");
    while (curr != NULL)     
    {
        printf("%4d", curr->data);   
        curr = curr->link;             
    }

    curr = first->link;      
    while (curr != NULL)    
    {
        listPointer link = curr->link;    
        free(curr);                       
        curr = link;                      
    }
   
    free(first);    

    return 0;
}