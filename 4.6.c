#include <stdio.h>
#include <string.h>
int main()
{
    char xing[20];
    char ming[20];
    printf("请输入您的名：");
        scanf("%s",ming);
    printf("请输入您的姓：");
        scanf("%s",xing);
    int x,m;
    x=strlen(xing);
    m=strlen(ming);
    printf("%s ",ming);
    printf("%s\n",xing);
    printf("%*d ",m,m);
    printf("%*d\n",x,x);

    printf("%s ",ming);  
    printf("%s\n",xing); 
    printf("%-*d ",m,m);
    printf("%-*d\n",x,x);
}

