#include <stdio.h>
void copy_arr(double * target1, double * source, int x);
void copy_ptr(double * target2, double * source, int x);
void copy_ptrs(double * target3, double * source, double * source2);

int main(void) 
{   
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    
    return 0;
} 
 
void copy_arr(double * target1, double * source, int x)
{
	int t;
	for (t=0; t < x; t++)
	{
		target1[t] = source[t];
		printf("%15.1f", target1[t]);
	}
	printf("\n");
}
void copy_ptr(double * target2, double * source, int x)
{
	int t;
	for (t=0; t < x; t++)
	{
		*(target2 + t) = *(source + t);
		printf("%15.1f", *(target2 + t));
	}
	printf("\n");
}
void copy_ptrs(double * target3, double * source, double * source2)
{
	double *i;
    int t;
    for(i = source, t = 0; i < source2; i++, t++)
    {
        *(target3 + t) = *i;
        printf("%15.1f", *(target3 + t));
    }
    printf("\n");
} 

