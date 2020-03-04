# include <stdio.h>
# include <ctype.h>
 
# define SIZE 40 
 
long get_word( char * st);
 
int main(void)
{
	char word[SIZE] ;
	long num = 0 ;
 
	num = get_word(word) ;
	if (num)
		printf("This word is %ld char : %s\n" , num , word);
 
	return 0 ;
}
 
long get_word( char * st)
{
	int prev , curr ;
	long num = 0 ;
 
	while ((curr = getchar()) != '\n')
	{
		if (isalpha(curr))
			st[num++] = curr ;
		else if (isalpha(prev))
		{
			st[num] = '\0' ;
			while (getchar() != '\n') ;
			break ;
		}
		
		prev = curr ;
	}
 
	return num ;
}
