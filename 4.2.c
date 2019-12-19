#include <stdio.h>
#include <string.h>
int main()
{
    char name[20];
    int a;
    printf("请输入您的名字：");
    scanf("%s",name);
    a=strlen(name)+3;
    printf("\"%s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("\"%-20s\"\n",name);
    printf("%*s\n",a,name);
       return 0;
}

