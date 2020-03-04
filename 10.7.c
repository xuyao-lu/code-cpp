# include <stdio.h>
 
void copy_arr(double target[] , double source[] , int n);
void print_arr(double ar[] , int n);
 
int main(void)
{
	double source[2][5] = {{1.1 , 2.2 , 3.3 , 4.4 , 5.5},{6.6 , 7.7 , 8.8 , 9.9 , 10.1}};
	double target1[2][5] ;
 
	for (int i = 0 ; i < 2 ; i++)
		print_arr(source[i] , 5);
 
	for (int i = 0 ; i < 2 ; i++)
		copy_arr(target1[i] , source[i] , 5) ;
 
	for (int i = 0 ; i < 2 ; i++)
		print_arr(target1[i] , 5);
 
	return 0 ;
}
 
void copy_arr(double target[] , double source[] , int n)
{
	for (int i = 0 ; i < n ; i++)
		target[i] = source[i] ;
}
 
void print_arr(double ar[] , int n)
{
	for (int i = 0 ; i < n ; i++)
		printf("%.2lf " , ar[i]);
 
	printf("\n");
}
