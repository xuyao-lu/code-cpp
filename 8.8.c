#include <stdio.h>
int main()
{
	float num1,num2,end;
	char ch,oper;
	printf("Enter the operation of your choice:\n");
	printf("a. add                s. subtract\n");
	printf("m. multiply           d. divide\n");
	printf("q. quit\n");
	while (scanf("%c",&ch)==1 && ch=='a' || ch=='s' || ch=='m' || ch=='d' && ch !='q')
	{
		printf("Enter first number:  ");
		while(scanf("%f",&num1)!=1)
		{
			while ((ch=getchar()) !='\n')
				putchar(ch);
			printf(" is not an number.\n");
			printf("请输入一个数字,例如 2.5, -1.78E8,or 3:");
		}
		printf("Enter seconds number:  ");
		while(scanf("%f",&num2)!=1)
		{
			while ((ch=getchar()) !='\n')
				putchar(ch);
			printf(" is not an number.\n");
			printf("请输入一个数字,例如 2.5, -1.78E8,or 3:");
		} 
		switch(ch)
		{
			case 'a':
				end=num1+num2;oper='+';break;
			case 's':
				end=num1-num2;oper='-';break;
			case 'm':
				end=num1*num2;oper='*';break;
			case 'd':
				while (num2==0)
				{
					printf("Enter a number other than 0:  ");
					scanf("%f",&num2);	
				}
				end=num1/num2;oper='/';break;
			default:printf("程序有错.\n");
		}
		printf("%g %c %g=%g\n",num1,oper,num2,end);
		printf("Enter the operation of your choice:\n");
		printf("a. add                s. subtract\n");
		printf("m. multiply           d. divide\n");
		printf("q. quit\n");
		while (getchar() !='\n')
			continue;
	}
	printf("Bye.\n"); 
	return 0;
 }

