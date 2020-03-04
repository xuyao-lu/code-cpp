#include <stdio.h>

double average(double a,double b);

int main()
{
    double a,b;

    printf("Please enter two numbers.\n");
    scanf("%lf %lf",&a,&b);

    printf("tiaohe average:%lf\n",average(a,b));

       return 0;
}

double average(double a,double b)
{
    double ave;

    ave=((1/a)+(1/b))/2;

    return 1/ave;
}

