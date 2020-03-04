#include <stdio.h>
 
void fibonacci(int x);

int main(void) 
{   
	int number;    
	    
	printf("Enter an integer (q to quit):\n");   
	while (scanf("%d", &number) == 1 )   
	{      
		if (number <= 0) 
			printf("Enter an integer which greater than 0:\n");
		else if (number == 1)
			printf("the 1 fibonacci number is 1.\n");
		else 
		{
			printf("the 1 fibonacci number is 1.\n");
			printf("the 2 fibonacci number is 1.\n");
			fibonacci(number);
		}
		printf("Enter a next integer (q to quit):\n");	  
	}   
	   
	return 0; 
} 
void fibonacci(int x) 
{
	int count;
	int a = 1;
	int b = 1;
	int t; 
	for (count = 2; count < x; count++)
		{
				t = a + b;
				a = b;
				b = t;
				printf("the %d fibonacci number is %d.\n", count + 1, t);
		} 
}

