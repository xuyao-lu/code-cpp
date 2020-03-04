#include <stdio.h>

int main()
{
    int n,sum=0,count=0;
    scanf("%d",&n);
    while(count++<n)
        sum=sum+count*count;
    printf("sum = %d\n",sum);
       return 0;
}

