#include <stdio.h>
float fanhui(float n,float m);

int main()
{
    float n,m;
    while(scanf("%f %f",&n,&m)&&n>=0&&n<=9&&m>=0&&m<=9)
    {
    printf("%f\n",fanhui(n,m)); 
    
    }
    return 0;
}
float fanhui (float n,float m)
{
    return (n-m)/(n*m);
}

