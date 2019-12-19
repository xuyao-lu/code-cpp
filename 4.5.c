#include <stdio.h>

int main()
{
    float v,s;

    scanf("%f %f",&v,&s);
    printf("At %.2f megabits per second, a file of %.2f megabttes\n",v,s);
    printf("downloads in %.2lf seconds.\n",s/v*8);

       return 0;
}

