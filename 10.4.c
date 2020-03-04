# include <stdio.h>
 
# define SIZE 10
 
double max_arr(double arr[] , int n );
 
int main(void)
{
	double arr[SIZE] ;
 
	for (int i = 0 ; i < SIZE ; i++)
	{
		arr[i] = i + 1 ;
		printf("%lf " , arr[i]);
	}
	printf("\n");
 
	printf("The array max index is %d\n" , max_arr(arr, SIZE));
 
	return 0 ;
}
 
double max_arr(double arr[] , int n )
{
	double max ;
	int index ;
 
	max = arr[0];
 
	for (int i = 0 ; i < n ; i++)
	{
		if (max < arr[i])	
		{
			index = i ;
			max = arr[i] ;
		}
	}
 
	return index;
}
