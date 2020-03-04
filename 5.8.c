#include <stdio.h>

int main()
{
    printf("This program computes moduli.\n");
    printf("Enter an intefer to serve as the second operand:");
    int n;
    scanf("%d",&n);
    printf("Now enter the first operand:");
    int m;
    scanf("%d",&m);
    while(m>0)
    {
        printf("%d %% %d is %d\n",m,n,m%n);
        printf("Enter next number for first operand (<= 0 to quit):");
        scanf("%d",&m);
    }
    printf("Done\n");
       return 0;
}

