#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[10];
    int grade[3];
};
typedef struct student STUDENT;
///////////////////////// 수정 /////////////////////////////////////
char *score_path = "/Users/barahana/Desktop/score.txt";
char *result_path = "/Users/barahana/Desktop/result.txt";
/////////////////////////// 수정 /////////////////////////////////////
int main()
{
    FILE *fp = fopen(score_path, "r");
    int num;
    char line[100];
    int i = 0;
    fgets(line,100,fp);
    sscanf(line, "%d ", &num);
    STUDENT* s = (STUDENT*)malloc(sizeof(*s) * num);
    
    
    double result[100];
    if(!fp){
        puts("Cannot open the file");
        exit(1);
    }
    
    fgets(line,100,fp);
    while(!feof(fp)){
        for(int j=0; j<3; j++)
            sscanf(line, "%s %d %d %d", s[i].name, &s[i].grade[0], &s[i].grade[1], &s[i].grade[2] );
        fgets(line,100,fp);
        i++;
    }
    fclose(fp);
    for(i=0;i<num;i++)
    {
        result[i] = (int)(s[i].grade[0] + s[i].grade[1] + s[i].grade[2])/3;
//        printf("%s, %2d %2d %2d\n", s[i].name, s[i].grade[0], s[i].grade[1], s[i].grade[2]);
    }
    FILE* result_f = fopen(result_path, "w");
    for(int n=0;n<num;n++)
    {
        printf("%s, %2.f\n", s[n].name, result[n]);
        fprintf(result_f, "%s, %2.f\n", s[n].name, result[n]);
    }
}
