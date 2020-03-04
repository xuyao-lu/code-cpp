# include <stdio.h>
# include <ctype.h>
 
# define SIZE 100 
 
char * get_input(char * st , int size);
 
int main(void)
{
	char st[SIZE] ;
 
	if (get_input(st , SIZE))
	fputs(st,stdout);
 
	return 0 ;
}
 

char * get_input(char * st , int size)
{
	char * ret_val = NULL ;
 
	if (ret_val = fgets(st , size , stdin))
	{
		while (*st)
		{
			if (isspace(*st))
			{
				*st = '\0' ;
				break ;
			}
			st++ ;
		}
	}
 
	return ret_val ;
}
