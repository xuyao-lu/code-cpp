#include <stdio.h>

int main()
{
    int n,count=0,sum=0;
    scanf("%d",&n);
    while(count++<n)
        sum=sum+count;
    printf("sum = %d\n",sum);

       return 0;
}

