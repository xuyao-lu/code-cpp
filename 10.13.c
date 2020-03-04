#include <stdio.h> 

#define ROWS 3 
#define COLS 5
  
void store(double ar[][COLS], int row); 
void showarr2(double ar[][COLS]);
double average(double ar[][COLS], int row);
double average2d(double ar[][COLS]); 
double max2d(double ar[][COLS]); 
 

 
int main(void)
{     
	double stuff[ROWS][COLS];     
	int row;
	          
	for (row = 0; row < ROWS; row++)
	{        
		printf("Enter %d numbers for row %d\n", COLS, row + 1);         
		store(stuff, row);
	}          
	printf("array contents:\n");
	     
	showarr2(stuff);
	         
	for (row = 0; row < ROWS; row++)
		printf("average value of row %d = %g\n", row + 1, average(stuff, row));
	     
	printf("average value of all rows = %g\n", average2d(stuff));
	     
	printf("largest value = %g\n", max2d(stuff));
	      
	printf("Bye!\n");         
	
	return 0;
} 
void store(double ar[][COLS], int row) 
{     
	int i;
	     
	for (i = 0; i < COLS; i++)    
	{         
		printf("Enter value #%d: ", i + 1);         
		scanf("%lf", &ar[row][i]);     
	} 
}
void showarr2(double ar[][COLS])
{     
	int row, col;          
	for (row = 0; row < ROWS; row++)     
	{         
		for (col = 0; col < COLS; col++)             
			printf("%g\t", ar[row][col]);         
		putchar('\n');     
	} 
}
double average(double ar[][COLS], int row)
{     
	int col;      
	double sum = 0.0;
	
	if (ROWS > 0)
	{	     
		for (col = 0; col < COLS; col++)      
	        sum +=  ar[row][col];
		return sum / COLS; 		          
	}
	else         
		return 0.0; 
}   
double average2d(double ar[][COLS])
{    
	int row, col;      
	double sum = 0.0;
	 
	if (ROWS > 0)
	{
		for (row = 0; row < ROWS; row++)     
		{         
			for (col = 0; col < COLS; col++)      
	        	sum +=  ar[row][col];	
		}
		return sum / (ROWS*COLS);           
	}
	else         
		return 0.0;  
} 
double max2d(double ar[][COLS])
{     
	int row, col;    
	double max = **ar;
	          
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			if (max < ar[row][col])                 
				max = ar[row][col]; 
		}             
			  
	}         
			  
	return max; 
} 

