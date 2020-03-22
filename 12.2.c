#include <stdio.h>


#ifndef DRAFT_PE12_2A_H
#define DRAFT_PE12_2A_H

#include<stdio.h>

static int mode;
static double km,fc;

void set_mode(int n);
void get_info();
void show_info();

#endif


void set_mpde(int n)
{
	mode = n;
}

void get_info()
{
	printf("Enter distance traveled in kilometers:");
	scanf("%lf",&km);
	printf("Enter fuel consumed in liters:");
	scanf("%lf",&fc);
}

void show_info()
{
	if(mode)
	{
		printf("Fuel consumption is %.1lf miles per gallon.\n",km/fc);
		
	}
	else
	{
		printf("Fuel consumption is %.2lf liter per 100 km.\n",fc/km);
	}
}

int main()
{
	int mode;
	
	printf("Enter 0 for metric mode,1 for us mode:");
	scanf("%d",&mode);
	while(mode>=0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1for us mode");
		printf("(-1 to quit)");
		scanf("%d",&mode);
	}
	printf("Done.\n");
	return 0;
}

