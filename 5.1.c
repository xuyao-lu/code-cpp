#include <stdio.h>

int main()
{
    const int a=60;
    int b;

    while(scanf("%d",&b)>0&&b>0)
    printf("%02d:%02d\n",b/a,b%a);
        

       return 0;
}

