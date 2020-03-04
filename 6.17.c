#include <stdio.h>
int main()
{	
	float get = 100;
	int n=1;
	
	while (get > 0)
	{
		get *= (108.0/100);
		get -= 10; 	
		n++;
	}
	printf("%d年后会取完钱\n",n);

	return 0;
}

