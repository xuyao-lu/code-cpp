#include <stdio.h>
#include <math.h>
int main()
{

    while(1)
    {
        int n;
        double sum=0;
        scanf("%d",&n);
        if(n<=0)
        break;
        for(int i=1;i<=n;i++)
        {
            sum+=1.0/i;
        }
        printf("%lf\n",sum);
        for(int j=1;j<=n;j++)
        {
            sum+=(1.0/j)*pow((-1),j+1);
        }
        printf("%lf\n",sum);
    }
       return 0;
}

