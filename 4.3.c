#include <stdio.h>

int main()
{
    float number;
    scanf("%f",&number);
    printf("The input is %.1f or %e\n",number,number);

    printf("The input is +%.3f or %E\n",number,number);
       return 0;
}

