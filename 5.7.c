#include <stdio.h>

    double sun(int n);
int main()
{
    double n;
    scanf("%lf",&n);

    printf("sum = %lf\n",sun(n));
       return 0;
}
double sun(int n)
{
    return n*n*n;
}

