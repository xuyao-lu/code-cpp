#include <stdio.h>
int main(void)
{	
	int total = 5;
	int weeks = 1;
	
	while (total < 150)
	{
		
		total = (total - weeks) * 2; 
		printf("%d周之后有%d个朋友\n",weeks, total);
		weeks++;
	}
	printf("%d周之后，社交圈中有稳定关系的成员超过150\n", weeks-1);

	return 0;
}
