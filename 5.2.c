#include <stdio.h>

int main()
{
    int number;
    printf("请输入一个数字：");
    scanf("%d",&number);
    int a=0;
    while(a<=10)
    {
        printf("%d\n",number+a);

        a++;
    
    }
       return 0;
}

