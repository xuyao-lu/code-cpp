#include <stdio.h>
#define SIZE 4

void sum_arr(double *arr1, double *arr2, double *sum, int lx); 
void show_arr(double * arr, int x);

int main(void)
{
    double arr1[SIZE] = {2, 4, 5, 8};
    double arr2[SIZE] = {1, 0, 4, 6};
    double sum[SIZE];
    
    sum_arr(arr1, arr2, sum, SIZE);
    show_arr(sum, SIZE);

	return 0;
}

void sum_arr(double *arr1, double *arr2, double *sum, int x) 
{
	int i;
	
    for ( i= 0; i < x; i++)
        sum[i] = arr1[i] + arr2[i];
}

void show_arr(double * arr, int x) 
{
	int i;
	
    for ( i= 0; i < x; i++)
        printf("%.1f\n", arr[i]);
}
