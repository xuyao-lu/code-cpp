#include <stdio.h>

int main()
{
    int a[10];
    for(int i=0;i<8;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=7;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
       return 0;
}

