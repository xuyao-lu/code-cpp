#include <stdio.h>

int main()
{
    int n,m;
    int sum=0;
    printf("Enter lower and upper inreger linits:");
    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;i++)
    {
        sum+=i*i;
    }
    printf("The sums of the squaers from %d to %d is %d.\n",n*n,m*m,sum);
    while(1)
    {
        sum=0;
        printf("Enter next set of limits:");
        scanf("%d %d",&n,&m);
        if(n>=m)
            break;
        for(int i=n;i<=m;i++)
        {
            sum+=i*i;
        }
        printf("The sums of the squares from %d to %d is %d\n",n*n,m*m,sum);
    }
    printf("Done\n");
       return 0;
}

