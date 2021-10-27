#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addMatrix(int*, int*, int);
void printMatrix(int*,int*,int);

int main(void)
{
    srand(time(NULL));
    int *arr1, *arr2, *result;
    int size;
    printf("Input size: ");
    scanf("%d", &size);
    arr1 = (int*)malloc(sizeof(int)*size);
    arr2 = (int*)malloc(sizeof(int)*size);
    result = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++)
    {
        arr1[i] = rand()%20;
        arr2[i] = rand()%20;
    }
    printMatrix(arr1, arr2, size);
    addMatrix(arr1, arr2, size);
}


void addMatrix(int *arr1, int *arr2, int size)
{
    printf(" result: ");
    for(int i=0; i<size; i++)
    {
        printf("%2d ", arr1[i]+arr2[i]);
    }
    printf("\n");
}
void printMatrix(int *arr1,int *arr2,int size)
{
    printf(" Array1: ");
    for(int i=0; i<size; i++)
    {
        printf("%2d ", arr1[i]);
    }
    printf("\n Array2: ");
    for(int i=0; i<size; i++)
    {
        printf("%2d ", arr2[i]);
    }
    printf("\n");
}
