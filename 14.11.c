
# include <stdio.h>
# include <windows.h>
# include <math.h>
 
int transform(double * source , double * traget , int n , double (*pfun)(double x));
void print_results(const double * source , int n);
 
int main(void)
{
	double source[4] = {1 , 2 , 3 , 4};
	double traget[4] = {0};
 
	transform(source , traget , 4 , sin);
	puts("source :");
	print_results(source , 4);
	puts("traget :");
	print_results(traget , 4);
 
	return 0 ;
}
 
int transform(double * source , double * traget , int n , double (*pfun)(double x))
{
	int i = 0 ;
 
	for (i = 0 ; i < n ; i++)
		traget[i] = pfun(source[i]);
	return i ; 
}
 
void print_results(const double * source , int n)
{
	int i;
	for ( i = 0 ; i < n ; i++)
	{
		printf("%lf " , source[i]);
	}
	putchar('\n');
}
