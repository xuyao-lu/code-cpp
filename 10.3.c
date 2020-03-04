# include <stdio.h>
 
# define SIZE 10
 
int max_arr(int arr[] , int n );
 
int main(void)
{
	int arr[SIZE] ;
 
	for (int i = 0 ; i < SIZE ; i++)
	{
		arr[i] = i + 1 ;
		printf("%d " , arr[i]);
	}
	printf("\n");
 
	printf("The array max is %d\n" , max_arr(arr, SIZE));
 
	return 0 ;
}
 
int max_arr(int arr[] , int n )
{
	int max = arr[0];
 
	for (int i = 0 ; i < n ; i++)
		if (max < arr[i])	
			max = arr[i] ;
 
	return max ;
}
