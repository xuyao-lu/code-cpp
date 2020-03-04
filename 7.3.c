#include <stdio.h>

int main()
{
    int number;
    int ou=0,ji=0,sum_ou=0,sum_ji=0;

    printf("请输入有一串数字，以空格间隔，以0结束：\n");

    while(scanf("%d",&number)!=EOF)
    {
        if(number==0)
            break;
        else if(number%2!=0)
        {
            ji++;
            sum_ji+=number;
        }
        else
        {
            ou++;
            sum_ou+=number;
        }
    }

    printf("输入的这串数字中，有%d个偶数（不包括0），这些偶数的平均数是%d\n",ou,sum_ou/ou);
    printf("输入的这串数字中，有%d个奇数，这些奇数的平均数是%d\n",ji,sum_ji/ji);

       return 0;
}

