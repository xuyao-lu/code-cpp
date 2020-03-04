#include <stdio.h>

int main()
{
    int number,i,j;
    int flag=1;

    printf("请输入一个正整数：\n");

    while(scanf("%d",&number)!=EOF&&number>0)
    {
        for(i=2;i<=number;i++)
        {
            for(j=2;j<=i;j++)
            {
                if(i%j==0&&j!=i)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                printf("%d\t",i);
            }
            flag=1;
        }
        break;
    }
       return 0;
}

