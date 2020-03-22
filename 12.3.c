
#ifndef DRAFT_PE12_2A_H
#define DRAFT_PE12_2A_H
 
#include <stdio.h>
 
void show_info(int mode);
 
#endif


#include "pe12-2a.h"
 
void show_info(int mode)
{
    double km, fc;
    printf("Enter　distance　traveled　in　kilometers:");
    scanf("%lf", &km);
    printf("Enter　fuel　consumed　in　liters:");
    scanf("%lf", &fc);
    if(mode)
    {
        printf("Fuel　consumption　is　%.1lf　miles　per　gallon.\n", km / fc);
    }
    else
    {
        printf("Fuel　consumption　is　%.2lf　liters　per　100　km.\n", fc / km);
    }
}
