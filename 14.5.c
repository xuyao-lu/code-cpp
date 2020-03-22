# include <stdio.h>
 
# define LEN 10 
# define CSIZE 4
 
 
struct name
{
	char sname[LEN] ;
	char name[LEN] ;
};
 
struct student
{
	struct name st_name;
	float grade[3] ;
	float average ;
};
 
void in_score(struct student * pstr);
float get_float(void);
void out_score(const struct student * pstr , int n);
 
int main(void)
{
	int i;
	struct student stu[CSIZE] = 
	{
		[0].st_name.sname = "zhang" , "san" ,
		[1].st_name.sname = "li" , "si" ,
		[2].st_name.sname = "wang" ,"wu" ,
		[3].st_name.sname = "zhao" , "liu"
	};
 
	for ( i = 0 ; i < CSIZE ; i++)
		in_score(&stu[i]) ;
 
	out_score(stu , CSIZE);
}
 
void in_score(struct student * pstr)
{
	static char * lession[] = {"语文" , "数学" ,"英语" };
	float sum = 0 ;
	int i ;
	for (i = 0 ; i < 3 ; i++)
	{
		printf("请输入%s %s的%s成绩:" , pstr->st_name.sname ,
				pstr->st_name.name , lession[i]);
		pstr->grade[i] = get_float() ;
 
		sum += pstr->grade[i] ;
	}
 
	pstr->average = sum / i ;
}
 
float get_float(void)
{
	float f = 0 ;
 
	while (scanf("%f" , &f) != 1 || f < 0 || f > 100)
	{
		while (getchar() != '\n') ;
		puts("无效输入,请重新输入");
	}
 
	return f ;
}
 
void out_score(const struct student * pstr , int n)
{
	int i;
	float sum = 0 ;
 
	printf("%10s %-10s %10s %10s %10s %10s \n" ,"姓" ,"名" , "语文" , "数学" , "英语" , "平均");
	for ( i = 0 ; i < n ; i++)
	{
		printf("%10s %-10s %10.1f %10.1f %10.1f %10.1f\n" ,
				pstr[i].st_name.sname , pstr[i].st_name.name ,
				pstr[i].grade[0] , pstr[i].grade[1] , pstr[i].grade[2],
				pstr[i].average) ;
		sum += pstr[i].average ;
	}
 
	printf("全班的平均成绩是:%.1f\n" , sum / n);
}
