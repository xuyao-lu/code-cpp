#include <stdio.h>
#include <math.h>
int main()
{
    printf("Enter a height in centimeters: ");
    float high;
    while (scanf("%f",&high)>0&&high>0)
    {
        float in=high/2.54;
        printf("%.1f cm = %.0lf feet, %.1f inches\n",high,floor(in/12),in-floor(in/12)*12);

        printf("Enter a height in centimeters (<=0 to quit) : ");
    }
        printf("bye\n");


    return 0;
}

