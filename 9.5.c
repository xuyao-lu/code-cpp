#include <stdio.h>

void larger_of(double* a,double*b);

int main()
{
    double a,b;

    printf("Please enter two number.\n");
    scanf("%lf %lf",&a,&b);
    printf("Former x = %.3f  y = %.3f\n",a,b);
    larger_of(&a,&b);
    printf("Now x = %.3f  y = %.3f\n",a,b);
       return 0;
}

void larger_of(double*a,double*b)
{
    if(*a>*b)
        *b=*a;
    else
        *a=*b;
}

