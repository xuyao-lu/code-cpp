# include <stdio.h>
 
# define SIZE 19
 
void sort_arr(int arr[] , int n );
 
int main(void)
{
	int arr[SIZE] ;
 
	for (int i = 0 ; i < SIZE ; i++)
	{
		arr[i] = i + 1 ;
		printf("%d " , arr[i]);
	}
	printf("\n");
 
	sort_arr(arr , SIZE) ;
 
	for (int i = 0 ; i < SIZE ; i++)
		printf("%d ", arr[i]);
	printf("\n");
 
	return 0 ;
}
 
void sort_arr(int arr[] , int n )
{
	int t ;
 
	for (int i = 0 ; i < n / 2 ; i++)
	{
		t = arr[i] ;
		arr[i] = arr[n - i - 1] ;
		arr[n - i - 1] = t ;
	}
 
}
