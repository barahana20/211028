#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  
#include <time.h>
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
listPointer createNode(int data)
{
    listPointer cur = malloc(sizeof(struct NODE));
    cur->data = data;
    cur->link = NULL;

    return cur;
}
listPointer appendNode(listPointer head, listPointer cur)
{
    listPointer nextnode = head;
    if (!head)
    {
        head = cur;
        return head;
    }
    while (nextnode->link)
        nextnode = nextnode->link;
    nextnode->link = cur;
    return head;
}
void printList(listPointer head)
{
    listPointer nextNode = head;
    while (nextNode)
    {
        printf("[%2d]", nextNode->data);
        nextNode = nextNode->link;
    }
}
void removeFirst(listPointer pHead)
{
    listPointer PNode = pHead->link;
    pHead->link = PNode->link;
    free(PNode);
}
void insertFront(listPointer* head, int data) {
    listPointer node = (listPointer)malloc(sizeof(struct NODE)); // 새 Node생성
    
    node->data = data;
    node->link = (*head);

    (*head) = node; // 첫 번째 Node를 가리키던 포인터를 새로 만들어진 Node를 가리키도록 함
}
int main()
{
    listPointer first = NULL;
    listPointer cur = NULL; 

    
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
        cur = createNode(atoi(ptr));
        first = appendNode(first, cur);
        ptr = strtok(NULL, " ");
    }
    printf("리스트:\n");
    printList(first);
    
    int input_num = 0;
    while (input_num >= 0)
    {
        printf("\n");
        printf("Input number: ");
        scanf("%d", &input_num);
        if (input_num % 10 >= 0 && input_num % 10 <= 4)
        {
            listPointer nextnode = first;
            while (nextnode)
            {
                if (nextnode->link == NULL)
                {
                    cur = createNode(input_num);
                    appendNode(first, cur);
                    break;
                }
                if (nextnode->data >= input_num && nextnode->link->data <= input_num)
                {
                    listPointer temp = malloc(sizeof(struct NODE));
                    temp->link = nextnode->link;
                    temp->data = input_num;
                    nextnode->link = temp;
                    break;
                }
                else if (nextnode->data < input_num)
                {
                    insertFront(first, nextnode->data);
                    insertFront(first, input_num);
                    break;
                }
                nextnode = nextnode->link;
            }
        }
            
        else if (input_num % 10 >= 5 && input_num % 10 <= 9)
        {
            listPointer nextnode = first;
            int Fact_check = 1;
            while (nextnode->link != NULL)
            {
                
                if (nextnode->link->data == input_num)
                {
                    removeFirst(nextnode);
                    Fact_check = 0;
                    break;
                }
                nextnode = nextnode->link;
            }
            if (Fact_check)
            {
                printf("삭제할 수 %d 없음.\n", input_num);
            }
            
            
        }

        listPointer curr = first->link;
        while (curr != NULL)
        {
            printf("[%2d]", curr->data);
            curr = curr->link;
        }
    }
    
    exit(1);
    /*
    curr = first->link;
    while (curr != NULL)
    {
        listPointer link = curr->link;
        free(curr);
        curr = link;
    }

    free(first);
    */
    return 0;
}