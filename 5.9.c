#include <stdio.h>
void Temperatures(double n);                                 
int main()
{
    double h;
    while( scanf("%lf", &h) == 1 )
        Temperatures(h);
    printf("退出\n");
    return 0;
}
void Temperatures(double n)                                 
 {                                                           
     const double a = 5.0;                                   
     const double b = 9.0;                                   
     const double s = 32.0;                                
     const double m = 273.16;                              
     double f, t;                                            
     t = a / b * ( n - s );                                
     f = t + m;                                            
     printf("h = %0.2f, t = %0.2f, f = %0.2f.\n",n,t,f);     
 }                                                           
