#include <stdio.h> 

#define ROWS 3 
#define COLUMN 5  

void times2(int arr[][COLUMN], int r); 
void showarr2(int arr[][COLUMN], int r); 

int main(void) 
{     
	int stuff[ROWS][COLUMN] = {    
			{1,2,3,4,5},                                 
			{6,7,8,-2,10},                                 
			{11,12,13,14,15}                            
	};
	     
	showarr2(stuff, ROWS);     
	putchar('\n');     
	times2(stuff, ROWS);     
	showarr2(stuff, ROWS);
	              
	return 0;
} 
void times2(int arr[][COLUMN], int r)  
{     
	int row, col;          
	
	for (row = 0; row < r; row++)         
	{
		for (col = 0; col < COLUMN; col++)             
		arr[row][col] *= 2; 
	}
} 
void showarr2(int arr[][COLUMN], int r)  
{
	int row, col;
	          
	for (row = 0; row < r; row++)    
	{         
		for (col = 0; col < COLUMN; col++)             
			printf("%d\t", arr[row][col]);         
		putchar('\n');     
	} 
}

