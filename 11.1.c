# include <stdio.h>
# include <string.h>
 
# define SIZE 100 
 
char * get_input(char * st , int size);
 
int main(void)
{
	char st[SIZE] ;
 
	if (get_input(st , SIZE))
		puts(st);
 
	return 0 ;
}
 
char * get_input(char * st , int size)
{
	char * str  = NULL ;
 
	str = fgets(st , size , stdin);
 
	return str ;
}
