# include <stdio.h>
 
# define LEN 20
 
struct person
{
	unsigned long long id ;
 
	struct 
	{
		char fname[LEN] ;
		char mname[LEN] ;
		char lname[LEN] ;
	};
};
 
void a_print(const struct person * pstc , int n);
void b_print(struct person ps);
 
int main(void)
{
	int i;
	struct person shebao[5] = 
	{
		2374856963 , "yuan" , "li" , "D" ,
		2374856964 , "meng" , "qi" , "D" ,
		2374856965 , "zhu" , "ge" , "liang" , 
		2374856966 , "xia" , "hou" , "dun" ,
		2374856967 , "si" , "ma" , "gang"
	};
	
	printf("Part_A:\n"); 
	printf("--------------------------\n");
	a_print(shebao , 5);
 
	printf("\nPart_B:\n");
	printf("--------------------------\n");
	for ( i = 0 ; i < 5 ; i++)
		b_print(shebao[i]);
 
	return 0 ;
}
 
void a_print(const struct person * pstc , int n)
{
	int i;
	for ( i = 0 ; i < n ; i++ , pstc++)
	{
		printf("%s , %s %s.\t  -- %llu\n",
				pstc->fname , pstc->lname , 
				pstc->mname , pstc->id);
	}
}
 
void b_print(struct person ps)
{
	printf("%s , %s %s.\t  -- %llu\n" , 
			ps.fname , ps.lname ,ps.mname , ps.id);
}
