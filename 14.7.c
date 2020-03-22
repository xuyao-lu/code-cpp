
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <windows.h>
 
# define MAXTITL 40 
# define MAXAUTL 40
# define MAXBKS 10
 
struct book 
{
	int 	del_flag;
	char 	title[MAXTITL] ;
	char 	author[MAXAUTL] ;
	float 	value ;
};
 
char * s_gets(char * st , int n) ;
FILE * file_open(const char * st) ;
long fdisplay(FILE * fp);
int menu_choice(FILE * fp);
void out_menu(void);
int fappend(FILE * fp);
int fmodify(FILE * fp);
int fdelete(FILE * fp);
int refresh(FILE * fp);
 
int main(void)
{
	struct book library[MAXBKS] ;
	int count = 0 ;
	int index , filecount ; 
	FILE * pbooks ;
	int size = sizeof(struct book);
 
	/*将编程清单14.14中这一段独立为 file_open();
	//打开文件
	if ((pbooks = fopen("book.dat" , "a + b")) == NULL)
	{
		fputs("Can't open book.dat file\n" , stderr);
		exit(EXIT_FAILURE);
	}
	*/
 
	/* 将编程清单中14.14中这一段独立为 fdisplay()函数
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count] , size , 1 , pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%s by %s : $%.2f\n" , library[count].title , library[count].author ,
				library[count].value);
		count++ ;
	}
	filecount = count ;
	*/
 
	pbooks = file_open("r + b");
	while (menu_choice(pbooks)) ;
 
	/* 将程序清单14.14这一段独立为fappend()函数
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets(library[count].title , MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author , MAXAUTL);
		puts("Now enter the value.");
		scanf("%f" , &library[count++].value);
		while (getchar() != '\n') ;
		if (count < MAXBKS)
			puts("Enter the next title.");
	}
	
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (index = 0 ; index < count ; index++)
			printf("%s by %s : $%.2f\n" , library[index].title ,
					library[index].author , library[index].value);
		fwrite(&library[filecount] , size , count - filecount , pbooks);
	}
	else
		puts("No books? Too bad.\n");
	*/
 
	puts("Bye.\n");
	fclose(pbooks);
 
	return 0 ;
}
 
char * s_gets(char * st , int n)
{
	char * ret_val = NULL ;
	char * find ;
 
	if (ret_val = fgets(st , n , stdin))
	{
		if (find = strchr(st , '\n'))
			*find = '\0' ;
		else
			while (getchar() != '\n') ;
	}
 
	return ret_val ;
}
 
FILE * file_open(const char * st)
{
	FILE * fp ;
 
	if ((fp = fopen("book.dat" , st)) == NULL) 			//如果打开失败
	{
		if ((fp = fopen("book.dat" , "w+b")) == NULL)		//新建文件
		{
			fputs("打开文件失败\n" , stderr);
			exit(EXIT_FAILURE);
		}
		fclose(fp);
 
		if ((fp = fopen("book.dat" , "r+b")) == NULL)		//重新以读写方式打开
		{
			fputs("打开文件失败\n" , stderr);
			exit(EXIT_FAILURE);
		}
	}
 
	return fp ;
}
 
int menu_choice(FILE * fp)
{
	int choice ;
    int i;
 
	out_menu();
	for ( i = 0 ; !scanf("%d", &choice); i++)
	{
		while (getchar() != '\n') ;
		puts("非法输入,请输入正确的选项");
 
		if ((i + 1) % 5 == 0)
			out_menu() ;
	}
	while (getchar() != '\n') ;
 
	switch (choice)
	{
		case 1:
			fdisplay(fp);
			break ;
		case 2:
			//修改
			fmodify(fp);
			break ;
		case 3:
			//添加
			fappend(fp);
			break ;
		case 4:
			//删除
			fdelete(fp);
			system("pause");
			break;
		case 5: 
			//退出文件操作
			//退出操作,将刷新文本,所有删除操作都将生效
			refresh(fp);
			choice = 0 ;
			break ;
		default :
			//出错
			choice = -1 ;
			puts("无效选择");
			system("pause");
			break;
	}
 
	return choice ;
}
 
void out_menu(void)
{ 
int i;
	static char * menu[] = 
	{
		"#################################",
		"请选择您需要的操作:" ,
		"1) 查看		2)修改",
		"3) 添加		4)删除",
		"5) 退出" , 
		"#################################"
	};
 
	system("cls");
 
	for(i = 0 ; i < sizeof(menu) / sizeof(menu[0]) ; i++)
		puts(menu[i]);
}
 
long fdisplay(FILE * fp)
{
	long count = 0 ;
	struct book tmp_book ;
 
	puts("==========================================");
	rewind(fp);
	while (fread(&tmp_book , sizeof(struct book), 1 , fp))
	{
		if (!tmp_book.del_flag)
		{
			printf("%s by %s : $%.2f\n" , tmp_book.title ,tmp_book.author , tmp_book.value);
			count++ ;
		}
	}
	rewind(fp);
	puts("==========================================");
 
	system("pause");
 
	return count ;
}
 
int fappend(FILE * fp)
{
	int state = 0 ;
	struct book tmp ;
 
	puts("请输入您要添加的书名:");
	puts("按[Enter]输入空行退出:");
	while (s_gets(tmp.title , MAXTITL) && tmp.title[0])
	{
		puts("请输入作者:");
		while (!s_gets(tmp.author , MAXAUTL))
			puts("输入非法,请重新输入作者");
 
		puts("请输入价格:");
		while (!scanf("%f" , &tmp.value) || tmp.value < 0)
		{
			while (getchar() != '\n') ;
			puts("无效数值,请重新输入");
		}
		while (getchar() != '\n') ;
		
		tmp.del_flag = 0 ;			//初始化删除标志位为0 , 表示未删除
		fseek(fp , 0L , SEEK_END); 		//文件指针定位到文件最后
		state = fwrite(&tmp , sizeof(struct book), 1 , fp);
		fflush(fp);
 
		puts("请输入下一本书名:");
	}
 
	rewind(fp);
 
	return state ;
}
 
int fmodify(FILE * fp)
{
	const char * tip = "无需修改请按[Enter]输入空行进入下一项";
	int state = 0 ;
	struct book tmp ;
	char bookname[MAXTITL];
	char tmp_st[MAXTITL] ; 
	float tmp_flt = 0 ; 
 
	//得到用户想要修改的 书名 并找到指定书名  未找到则回复用户未找到 
	puts("请输入您想要修改的书名:");
	s_gets(bookname , MAXTITL);
 
	rewind(fp);
	while (state = fread(&tmp , sizeof(struct book) , 1 , fp))
	{
		if (strcmp(tmp.title , bookname) == 0)
			break ;
	}
 
 
	if (state)
	{
		state = 0 ;	//初始化状态值;
 
		puts("===============================");
		printf("%s\n请输入新的书名,%s\n",tmp.title , tip);
		while (!s_gets(tmp_st ,MAXTITL))
			puts("非法输入");
		if (*tmp_st && strcmp(tmp.title , tmp_st) != 0)
			strcpy(tmp.title , tmp_st);
		strcpy(tmp_st , "");
 
		puts("===============================");
		printf("%s\n请输入新的作者,%s\n",tmp.author , tip);
		while (!s_gets(tmp_st , MAXTITL))
			puts("非法输入");
		if (*tmp_st && strcmp(tmp.author , tmp_st) != 0)
			strcpy(tmp.author , tmp_st);
		strcpy(tmp_st , "") ;
 
		puts("===============================");
		printf("$%.2f\n请输入新的价格,%s\n" , tmp.value , tip);
		while (!s_gets(tmp_st , MAXTITL) || (tmp_flt = atof(tmp_st)) < 0) 
			printf("无效输入");
		if (tmp_flt > 0)
			tmp.value = tmp_flt ;
		strcpy(tmp_st , "");
 
		tmp.del_flag = 0 ;		//初始化删除标志位为0 ,表示未删除
		puts("===============================");
		printf("将修改为:\n书名:%s\n作者:%s\n价格:%.2f\n " , 
				tmp.title , tmp.author , tmp.value);
		puts("-------------------------------");
		puts("确定修改吗?(y/n)");
		if (s_gets(tmp_st , MAXTITL) && tolower(tmp_st[0]) == 'y')
		{
			fseek(fp , -((long)sizeof(struct book)) , SEEK_CUR);
			state = fwrite(&tmp , sizeof(struct book) , 1 , fp);
			fflush(fp);
		}
		
		if (state)
		{
			puts("===============================");
			puts("修改成功!\n任意键返回菜单页面");
			getchar();
		}
	}
	else 
	{
		puts("===============================");
		puts("书名不存在,请检查输入.\n任意键返回菜单页面");
		getchar();
	}
 
	rewind(fp);
	
	return state ; 
}
 
int fdelete(FILE * fp)
{
 	int state = 0 ;
	struct book tmp ;
	char tmp_st[MAXTITL] ;
	int find = 0 ;
	int count = 0;
 
	// 判断文件是否有内容 , 无内容则不能修改
	fseek(fp , 0L , SEEK_END);
	if (ftell(fp) == 0)
	{
		puts("错误:文件内无内容");
		return 0 ;
	}
	rewind(fp);
 
	puts("请输入您要删除的书名");
	if (s_gets(tmp_st , MAXTITL))
	{
		rewind(fp);
		while (find = fread(&tmp , sizeof(struct book) , 1 , fp))
		{
			if (strcmp(tmp.title , tmp_st) == 0)		//如果找到了,就将删除标志位置1
			{
				tmp.del_flag = 1;			//删除标志位置1
				fseek(fp , -((long)sizeof(struct book)) , SEEK_CUR); //定位到此记录
				fwrite(&tmp , sizeof(struct book) , 1 , fp);	//覆盖此记录
				fflush(fp);				//刷新文件
				break ;
			}
		}
		if (find)
			puts("删除成功,返回菜单页面");
		else
			puts("未找到该书籍,请确认书名,或者添加该书籍");
 
		rewind(fp);
	}
	else 
	{
		puts("无效输入");
		state = 0 ;
	} 
 
	return state ;
}
 
int refresh(FILE * fp)
{
	FILE * fp_tmp ;
	struct book bk_tmp ;
	int state  = 0 ;
 
	if (!(fp_tmp = fopen("book.tmp" , "wb+")))
	{
		fputs("关闭文件失败" , stderr);
		exit(EXIT_FAILURE);
	}
 
	rewind(fp) ;
	while (fread(&bk_tmp , sizeof(struct book) , 1 , fp))
	{
		if (!bk_tmp.del_flag)
		{
			if (!fwrite(&bk_tmp , sizeof(struct book) , 1 , fp_tmp))
			{
				fputs("写入文件失败" , stderr);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(fp_tmp);
	fclose(fp);
	system("del book.dat");
	system("rename book.tmp book.dat");
 
	return state ;
}
 
