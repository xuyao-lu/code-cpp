#include <stdio.h>

int main()
{
    float high;

    char name[10];
    printf("请输入您的身高（英寸）：\n");
    scanf("%f",&high);
    printf("请输入您的名字：\n");
    scanf("%s",name);
    printf("%s,you are %.3f feet tall\n",name,high/12.0);


    float high1;
    char name1[10];
    printf("请输入您的身高（厘米）：\n");
    scanf("%f",&high1);
    printf("请输入您的名字：\n");
    scanf("%s",name1);
    printf("%s,you high is %.3f\n",name1,high1/100);

       return 0;
}

