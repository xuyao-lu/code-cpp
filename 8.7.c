# include <stdio.h>
 
# define ￥300 0.15
# define ￥150 0.2
# define ￥450 0.25
# define $1 8.75
# define $2 9.33
# define $3 10.00
# define $4 11.20 
 
int main(void)
{
	double work_hours = 0 ;
	double total_income = 0 ;
	double tax = 0 ;
	double net_income = 0 ;
	double hr_income = 0 ;
	char answer ;
 
 
	while (1)
	{	
		printf("Enter the number corresponding to the desired pay rate or action :\n");
		for(int i = 0 ; i < 100 ; i++)
			putchar('*');
		putchar('\n');
		printf("%-50s %-50s\n" , "a) $8.75/hr" , "b) $9.33/hr");
		printf("%-50s %-50s\n" , "c) ￥3000.00/hr" , "d) ￥3001.20/hr");
		printf("q) quit\n");
		for(int i = 0 ; i < 100 ; i++)
			putchar('*');
		putchar('\n');
 
		answer = getchar() ;
		while(getchar() != '\n')
			continue ;
		
		switch (answer)
		{
			case 'a' :
				hr_income = $1;
				break ;
			case 'b' :
				hr_income = $2 ;
				break ;
			case 'c' :
				hr_income = $3 ;
				break ;
			case 'd' :
				hr_income = $4 ;
				break ;
			case 'q' :
				printf("Bye!");
				return 0 ;
			default :
				continue ;
		}
 
		printf("Please enter your work hours for week :\n");
		scanf("%lf" , &work_hours);
 
		if (work_hours > 40)
			total_income = hr_income * 40 + (1.5 * hr_income * (work_hours - 40));
		else 
			total_income = hr_income * work_hours ;
 
		if (total_income <= 300)
		{
			tax = total_income * ￥300 ;
			net_income = total_income - tax ;
		}
		else if (total_income <= 450)
		{
			tax = (total_income - 300) * ￥150 + 300 * ￥300 ;
			net_income = total_income - tax ;
		}
		else 
		{
			tax = (total_income - 450) * ￥450 + 150 * ￥150 + 300 * ￥300 ;
			net_income = total_income - tax ;
		}
 
		printf("Total income = %lf , tax = %lf , net income = %lf \n" , total_income , tax , net_income);
	}
 
	return 0 ;
}
