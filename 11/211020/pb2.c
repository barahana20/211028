#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void printList(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d ", p->data);
		p = p->link;
	} while (p != head);
	printf("%d ", p->data);
}

ListNode* insertFirst(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}
ListNode* insertLast(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}


int main(void) {
	ListNode* head = NULL;
	ListNode* rear = head;
	FILE* fp = fopen("poly1.txt", "r");
	if (!fp)
	{
		printf("error");
		exit(1);
	}
	char line[100];
	fgets(line, 100, fp);
	char* ptr = strtok(line, " ");
	head = insertLast(head, 50);
	printf("%d\n", head->data);
	while (ptr != NULL)
	{
		int num = atoi(ptr);
		if (num < 0)
		{
			head = insertFirst(head, num);
			printList(head);
			printf("\n");
		}
		else
		{
			head = insertLast(head, num);

			printList(head);
			printf("\n");
		}
		ptr = strtok(NULL, " ");

	}
	
	return 0;
}
