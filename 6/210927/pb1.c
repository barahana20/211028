#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct in_information {
    char name[21];
    int num;
    int order;
} info;

int main(void)
{
    info in_info[100];
    info add_info[100];
    info total_info[200];
    FILE* in_fp = fopen("C:\\Users\\barah\\Desktop\\in.txt", "r");// 파일 읽기모드로 열기
    FILE* add_fp = fopen("C:\\Users\\barah\\Desktop\\add.txt", "r");// 파일 읽기모드로 열기
    FILE* out_fp = fopen("C:\\Users\\barah\\Desktop\\out.txt", "w");
    if (in_fp == NULL) {
        printf("fail to read file");
        return 0;
    }
    if (add_fp == NULL) {
        printf("fail to read file");
        return 0;
    }
    char in_buffer[1001], * token;
    char add_buffer[1001];

    int i = 0;
    int in_idx = 0;
    while (!feof(in_fp)) {
        i = 0;//i초기화
        fgets(in_buffer, 1001, in_fp);
        token = strtok(in_buffer, " "); // 
        while (token != NULL) {

            if (i == 1) {
                strcpy(in_info[in_idx].name, token);
                if (in_info[in_idx].name[strlen(in_info[in_idx].name) - 1] == '\n')
                    in_info[in_idx].name[strlen(in_info[in_idx].name) - 1] = '\0';
                
            }
            else if (i == 0) {
                in_info[in_idx].num = atoi(token);
            }
            i++;
            token = strtok(NULL, " ");
        }
        in_idx++;
    }
    int add_idx = 0;
    while (!feof(add_fp)) {
        i = 0;//i초기화
        fgets(add_buffer, 1001, add_fp);
        token = strtok(add_buffer, " "); // 
        while (token != NULL) {

            if (i == 1) {
                strcpy(add_info[add_idx].name, token);
                if (add_info[add_idx].name[strlen(add_info[add_idx].name) - 1] == '\n')
                    add_info[add_idx].name[strlen(add_info[add_idx].name) - 1] = '\0';

            }
            else if (i == 0) {
                add_info[add_idx].num = atoi(token);
            }
            i++;
            token = strtok(NULL, " ");
        }
        add_idx++;
    }
    
    int arr[200][1] = { 0, };
    for (int i = 0; i < in_idx; i++)
    {
        total_info[i].num = in_info[i].num;
        strcpy(total_info[i].name, in_info[i].name);
    }
    for (int i = in_idx; i < add_idx + in_idx; i++)
    {
        total_info[i].num = add_info[i-in_idx].num;
        strcpy(total_info[i].name, add_info[i - in_idx].name);
    }
    int temp_num;
    char temp_name[21];
    for (int i = 0; i < in_idx+add_idx; i++)    // 요소의 개수만큼 반복
    {
        
        for (int j = 0; j < in_idx + add_idx - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            
            if (total_info[j].num > total_info[j + 1].num)          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp_num = total_info[j].num;
                total_info[j].num = total_info[j + 1].num;
                total_info[j + 1].num = temp_num; // 다음 요소로 보냄
               
                strcpy(temp_name, total_info[j].name);
                strcpy(total_info[j].name, total_info[j + 1].name);
                strcpy(total_info[j + 1].name, temp_name);
                
            }
        }
    }
    int j;
    int equal_count = 0;
    for (int i = 0; i < add_idx + in_idx - 1; i++)
    {
        if (total_info[i].num == total_info[i+1].num)
        {
            for (j = i; j < add_idx + in_idx-1; j++)
            {
                total_info[j].num = total_info[j + 1].num;
                strcpy(total_info[j].name, total_info[j + 1].name);
                
            }
            total_info[j].num = -1;
            strcpy(total_info[j].name, "\0");
            strcpy(total_info[i].name, "ERROR");
            equal_count++;
        }
    }
    for (int i = 0; i < add_idx + in_idx-equal_count; i++)
        printf("%2d,   %s\n", total_info[i].num, total_info[i].name);
    for (int i = 0; i < add_idx + in_idx - equal_count; i++)
        fprintf(out_fp, "%d %s\n", total_info[i].num, total_info[i].name);


    /*
    //읽은 내용이 잘 저장됐는지 출력
    for (int i = 0; i < in_idx; i++) {
        printf("%d %s\n", in_info[i].num, in_info[i].name);
    }
    for (int i = 0; i < add_idx; i++) {
        printf("%d %s\n", add_info[i].num, add_info[i].name);
    }*/
    fclose(in_fp); // 파일 닫기
    fclose(add_fp);
    return 0;
    
}
