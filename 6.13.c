#include <stdio.h>
#include <math.h>
#define N 8
int main()
{
    int a[N];
    for(int i=1;i<=N;i++)
    {
        a[i]=pow(2,i);
    }
    int i=1;
    do{

        printf("%5d",a[i++]);
        if(i==9)
            break;
    }while(1);

printf("\n");
       return 0;
}

