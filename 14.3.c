# include <stdio.h>
# include <string.h>
 
# define MAXTITL 40 
# define MAXAUTL 40 
# define MAXBKS 100
 
char * s_gets(char * st , int n);
 
struct book
{
	char title[MAXTITL] ;	//书名
	char author[MAXAUTL] ;	//作者
	float value ;		//价格
};
 
int main(void)
{
	int i,j; 
	struct book library[MAXBKS] ;
	int count = 0 ; 
	int index ; 
 
	printf("Please enter the book title .\n");
	printf("Press [enter] at the start of line to stop .\n");
	while (count < MAXBKS && s_gets(library[count].title , MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author , MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f" , &library[count++].value);
		while (getchar() != '\n') ;
		if (count < MAXBKS)
			printf("Enter the next title . \n");
	}
 
	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0 ; index < count ; index++)
			printf("%s by %s : $%.2f\n" , library[index].title , library[index].author,
					library[index].value);
 
		
		//按字符声明顺序(选择排序)
		for (i = 0  , j = 0 ; i < count - 1 ; i++)
		{
			int min_index = i;
			for (j = i + 1 ; j < count ; j++)
				if (strcmp(library[min_index].title , library[j].title) > 0)
					min_index = j ;
 
			struct book tmp_book = library[i] ;
			library[i] = library[min_index] ;
			library[min_index] = tmp_book ;
		}
 
		puts("\n按字符声明排序如下");
		for (index = 0 ; index < count ; index++)
			printf("%s by %s : $%.2f\n" , library[index].title , library[index].author,
					library[index].value);
		
		//按价格顺序(冒泡排序)
		for (i = 0 ; i < count - 1 ; i++)
		{
			for ( j = 0 ; j < count - 1 - i ; j++)
			{
				if (library[j].value > library[j + 1].value)
				{
					struct book tmp_book = library[j];
					library[j] = library[j + 1] ;
					library[j + 1] = tmp_book ;
				}
			}
		}
		puts("\n按价格.排序如下");
		for (index = 0 ; index < count ; index++)
			printf("%s by %s : $%.2f\n" , library[index].title , library[index].author,
					library[index].value);
		
	}
	else
		printf("No books? Too bad.\n");
 
	return 0 ;
}
 
char * s_gets(char * st , int n)
{
	char * ret_val ;
	char * find ;
 
	ret_val = fgets(st , n , stdin);
 
	if (ret_val)
	{
		find = strchr(st , '\n');
		if (find)
			*find = '\0' ;
		else
			while (getchar() != '\n') ;
	}
 
	return ret_val ;
}
