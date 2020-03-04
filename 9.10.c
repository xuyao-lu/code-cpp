#include <stdio.h>

void to_base_n(unsigned long n,int p);

int main()
{
    unsigned long number;
    int radix;

    printf("Please enter an integer and a radix(q to quit).\n");

    while(scanf("%lu %d",&number,&radix)==2)
    {
        if(radix<2||radix>10)
            printf("The tadix must be between 2 to 10");
        else
        {
            printf("result:");
            to_base_n(number,radix);
            putchar('\n');
        }
        printf("Enter an integer and a radix.(q to quit)\n");
    }
    printf("bye\n");
       return 0;
}

void to_base_n(unsigned long n,int p)
{
    int r;

    r=n%p;
    if(n>=p)
        to_base_n(n/p,p);
    printf("%d",r);
}
