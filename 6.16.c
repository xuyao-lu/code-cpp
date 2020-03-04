#include <stdio.h>
int main()
{
    int n=0;
    double a=100,e=100;

    while(e<=a)
    {
        a+=100*0.1;
        e*=1.05;
        n++;
    }
    printf("%d\n%10lf%10lf\n",n,a,e);
       return 0;
}
