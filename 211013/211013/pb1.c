#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False -1
typedef struct
{
	int int_key;
	char char_key;

}element;
int cir_front = 0;
int cir_rear = 0;
int front = -1;
int rear = -1;
element error_key;

int cir_addq(element item, element* cir_queue, int max_queue_size);
int cir_deleteq(element* cir_queue, int max_queue_size);

int addq(element item, element* queue, int max_queue_size);
int deleteq(element* queue, int max_queue_size);

int cir_addq(element item, element* cir_queue, int max_queue_size)
{
	cir_rear = (cir_rear + 1) % max_queue_size;
	//printf("cir_front = %d\ncir_rear = %d\n", cir_front, cir_rear);

	cir_queue[cir_rear].int_key = item.int_key;
	return True;
}

int cir_deleteq(element* cir_queue, int max_queue_size)
{

	cir_front = (cir_front + 1) % max_queue_size;
	//printf("cir_front = %d\ncir_rear = %d\n", cir_front, cir_rear);

	return True;
}
int addq(element item, element* queue, int max_queue_size)
{
	queue[++rear] = item;
	//printf("add) front = %d\trear = %d\n", front, rear);
	return True;
}

int deleteq(element* queue, int max_queue_size)
{

	if (front >= max_queue_size - 1)
		return False;
	front = (front + 1);

	//printf("del) front = %d\trear = %d\n", front, rear);

	return queue[front].int_key; // 방금 제거된 원소를 return
}




int main()
{
	element* queue;
	element* cir_queue;
	element item;
	printf("input size:");
	scanf("%d", &item.int_key);
	int max_queue_size = item.int_key;
	queue = (element*)malloc(sizeof(element) * max_queue_size);
	cir_queue = (element*)malloc(sizeof(element) * max_queue_size);
	printf("Queue size: %d\n", item.int_key);
	rewind(stdin);
	while (1)
	{
		printf("Input:");
		scanf("%c", &item.char_key);
		fflush(stdin);
		if (item.char_key == 'q')
		{
			printf("quit\n");
			break;
		}

		else if (item.char_key == 'd')
		{
			rewind(stdin);
			deleteq(queue, max_queue_size);
			cir_deleteq(cir_queue, max_queue_size);
			if (cir_rear == cir_front)
			{
				printf("Circular Queue is empty!\n");
			}
			else
			{

				printf("Circular queue: ");
				for (int i = (cir_front + 1) % max_queue_size; i != (cir_rear + 1) % max_queue_size; i = (i + 1) % max_queue_size)
					printf("%d ", cir_queue[i].int_key);
				printf("\n");

			}
			if (rear == front)
			{
				printf("List Queue is empty!\n");
			}
			else
			{

				printf("List queue: ");
				for (int i = front + 1; i <= rear; i++)
					printf("%d ", queue[i].int_key);
				printf("\n");
			}
		}

		else if (item.char_key == 'a')
		{
			scanf("%d", &item.int_key);
			rewind(stdin);

			if (cir_front == (cir_rear + 1) % max_queue_size) // full 확인
			{
				printf("Circular Queue is full!\n");
			}
			else
			{
				cir_addq(item, cir_queue, max_queue_size);
				printf("Circular queue: ");

				for (int i = (cir_front + 1) % max_queue_size; i != (cir_rear + 1) % max_queue_size; i = (i + 1) % max_queue_size)
					printf("%d ", cir_queue[i].int_key);
				printf("\n");
			}

			if (rear >= max_queue_size - 1)
				printf("List Queue is full!\n");
			else
			{
				addq(item, queue, max_queue_size);
				printf("List queue: ");
				for (int i = front + 1; i < rear + 1; i++)
					printf("%d ", queue[i].int_key);
				printf("\n");
			}

		}
		fflush(stdin);
	}
	free(queue);
	free(cir_queue);
}