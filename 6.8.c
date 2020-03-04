#include <stdio.h>

int main()
{
    float n,m;
    while(scanf("%f %f",&n,&m)&&n<=9&&n>=0&&m<=9&&m>=0)
    {
        printf("%f\n",(n-m)/(n*m));
    }
       return 0;
}

