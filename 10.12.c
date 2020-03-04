# include <stdio.h>
 
# define MONTHS 12
# define YEARS 5
 
float sum_year(const float ar[] , int n);
void sum_month(const float ar[][MONTHS] , int year);
 
int main(void)
{
	const float rain[YEARS][MONTHS] = 
	{
		{4.3 , 4.3 , 4.3 , 3.0 , 2.0 , 1.2 , 0.2 , 0.2 , 0.4 , 2.4 , 3.5 , 6.6} ,
		{8.5 , 8.2 , 1.2 , 1.6 , 2.4 , 0.0 , 5.2 , 0.9 , 0.3 , 0.9 , 1.4 , 7.3} ,
		{9.1 , 8.5 , 6.7 , 4.3 , 2.1 , 0.8 , 0.2 , 0.2 , 1.1 , 2.3 , 6.1 , 8.4} ,
		{7.2 , 9.9 , 8.4 , 3.3 , 1.2 , 0.8 , 0.4 , 0.0 , 0.6 , 1.7 , 4.3 , 6.2} ,
		{7.6 , 5.6 , 3.8 , 2.8 , 3.8 , 0.2 , 0.0 , 0.0 , 0.0 , 1.3 , 2.6 , 5.2}
	} ;
	int year , month ; 
	float subtot , total ;
	const float * p ;
 
	for (year = 0 , total = 0 ; year < YEARS ; year++)
	{
		p = rain[year];
		subtot = sum_year(p , MONTHS);
 
		printf("%5d %15.1f\n" , 2010 + year , subtot);
		total += subtot ;
	}
	printf("\nThe yearly average is %.1f inches.\n\n" , total / YEARS);
 
	sum_month(rain , YEARS) ;
 
	return 0 ;
} 
 
float sum_year(const float ar[] , int n)
{
	float sum  = 0 ;
 
	for (int i = 0 ; i < n ; i++)
		sum += ar[i] ;
 
	return sum ;
}
 
void sum_month(const float ar[][MONTHS] , int year)
{
	float total ;
 
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
 
	for (int mon = 0 ; mon < MONTHS ; mon++)
	{
		total = 0 ;
		for(int y = 0 ; y < year ; y++)
			total += ar[y][mon] ;
		printf("%4.1f " , total / YEARS);
	}
	printf("\n");
}
