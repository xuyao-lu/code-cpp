# include <stdio.h>
 
void copy_arr(double target[] , double source[] , int n);
void print_arr(double ar[] , int n);
 
int main(void)
{
	double source[7] = {1.1 , 2.2 , 3.3 , 4.4 , 5.5 , 6.6 , 7.7};
	double target1[3];
 
	print_arr(source, 7);
 
	copy_arr(target1 , &source[2] , 3) ;
 
	print_arr(target1, 3);
 
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
} 
