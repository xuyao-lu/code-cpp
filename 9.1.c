#include <stdio.h>

double min(double a,double b);

int main()
{
    double x,y;

    printf("Please rnter two numbers:\n");

    scanf("%lf %lf",&x,&y);

    printf("The smallest is %lf.\n",min(x,y));

       return 0;
}

double min(double a,double b)
{
    return a<b?a:b;
}

