#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_COL 101

typedef struct structure {
    int col;
    int row;
    int value;
}term;
term a[MAX_COL];
term b[MAX_COL];
void fastTranspose(term a[], term b[])
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols; b[0].col = a[0].row;
    b[0].value = numTerms;
    if (numTerms > 0) {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;
        for (i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col; b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main()
{
    FILE* a_pfile;
    FILE* b_pfile;
    char str_read[100];
    int a_c = 0;
    a_pfile = fopen("C:\\Users\\barah\\Desktop\\m2.txt", "r");
    b_pfile = fopen("C:\\Users\\barah\\Desktop\\m2.txt", "r");
    int a_range[10] = { 0 };
    int b_range[10] = { 0 };
    int a_list[101];
    int b_list[101];
    if (a_pfile == NULL)
        printf("error");
    while (fscanf(a_pfile, "%d", &a_list[a_c]) != -1)
        a_c++;

    int b_c = 0;
    while (fscanf(b_pfile, "%d", &b_list[b_c]) != -1)
        b_c++;
    for (int i = 0; i < a_c; i+=3)
    {
        a[i/3].row = a_list[i];
        a[i/3].col = a_list[i + 1];
        a[i/3].value = a_list[i + 2];
    }

    fastTranspose(a, b);
    int result_arr[200][200] = { 0, };

    printf("Before Transposing\n");
    for (int i = 0; i <= a[0].value; i++)
    {
        result_arr[a[i].row][a[i].col] = a[i].value;
    }
    for (int i = 0; i < a[0].row; i++)
    {
        for (int j = 0; j < a[0].col; j++)
            printf("%3d", result_arr[i][j]);
        printf("\n");
    }

    int result_arr1[200][200] = { 0, };
    printf("\n");
    printf("After Transposing\n");
    for (int i = 0; i <= b[0].value; i++)
    {
        result_arr1[b[i].row][b[i].col] = b[i].value;
    }
    for (int i = 0; i < b[0].row; i++)
    {
        for (int j = 0; j < b[0].col; j++)
            printf("%3d", result_arr1[i][j]);
        printf("\n");
    }
    
    return 0;
}