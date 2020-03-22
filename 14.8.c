
# include <stdio.h>
# include <ctype.h>
# include <windows.h>
 
# define NAME_LEN 50 
# define SEAT_COUNT 12
 
typedef struct 
{
	int number ;
	int selected ;
	char name[NAME_LEN] ;
	char s_name[NAME_LEN];
}seat;
 
 
int initialize_seat(seat * pstr , int n);
void print_menu(void);
char choice_menu(void);
int switch_menu(int choice , seat * pstr);
int empty_seat_count(const seat * pstr , int n);
int show_seat_list(const seat * pstr , int n);
int sort_seat_list(seat * pstr , int n);
int choice_seat(seat * pstr , int n);
int delte_seat(seat * pstr , int n);
char * s_gets(char * st , int n);
 
int main(void)
{
	seat plane_seat[SEAT_COUNT] ;
 
	initialize_seat(plane_seat , SEAT_COUNT);			//初始化座位
 
	while (switch_menu(choice_menu() , plane_seat)) ;
 
	puts("Bye. See you next!");
 
	return 0 ;
}
 
int initialize_seat(seat * pstr , int n)
{
	int i;
 
	for (i = 0 ; i < n ; i++)
	{
		pstr[i].number = i + 1 ;
		pstr[i].selected = 0 ;
		pstr[i].name[0] = '\0' ;
		pstr[i].s_name[0] = '\0' ;
	}
 
	return (i == n ? i : 0) ;
}
 
char choice_menu(void)
{
	char ch ;
 
	print_menu();
	while (!scanf(" %c" , &ch) || !isalpha(ch = tolower(ch)))
	{
		while (getchar() != '\n') ;
		puts("输入非法,请重新输入");
	}
 
	while (getchar() != '\n') ;
 
	return ch ;
}
 
void print_menu(void)
{
	int i;
	static char * menu[] = 
	{
		"To choose a function enter its letter label:",
		"a) Show number of empty seats",
		"b) Show list of empty seats",
		"c) Show alphabetical list of seats",
		"d) Assign a customer to a seat assignment",
		"e) Delete a seat assignment",
		"f) Quit"
	};
 
	system("cls");
	for ( i = 0 ; i < sizeof(menu) / sizeof(menu[0]) ; i++)
		puts(menu[i]);
}
 
int switch_menu(int choice , seat * pstr)
{
	switch (choice)
	{
		case 'a' :
			//显示未预定的座位数量
			empty_seat_count(pstr , SEAT_COUNT);
			system("pause");
			return 1;
		case 'b' :
			//显示空的座位列表
			show_seat_list(pstr , SEAT_COUNT);
			system("pause");
			return 1 ;
		case 'c' :
			//按字母顺序显示座位列表
			sort_seat_list(pstr , SEAT_COUNT) ;
			system("pause");
			return 1 ;
		case 'd' :
			//为客户分配座位
			choice_seat(pstr , SEAT_COUNT);
			system("cls");
			show_seat_list(pstr , SEAT_COUNT);
			system("pause");
			return 1 ;
		case 'e' :
			//删除座位分配
			delte_seat(pstr , SEAT_COUNT);
			system("cls");
			show_seat_list(pstr , SEAT_COUNT);
			system("pause");
			return 1 ;
		case 'f' :
			//退出
			return 0 ;
		default :
			//错误选择
			puts("无效选择,请重新选择");
			system("pause");
			return 1 ;
	}
}
 
int empty_seat_count(const seat * pstr , int n)
{
	int i;
	int count = 0 ;
 
	for ( i = 0 ; i < n ; i++)
	{
		if (pstr[i].selected == 0)
			count++ ;
	}
	printf("现在空座为还剩%d个\n" , count);
 
	return count ;
}
 
int show_seat_list(const seat * pstr , int n)
{
	int i ;
 
	puts("当前座位信息:");
	
	for (i = 0 ; i < n ; i++)
	{
		if (pstr[i].selected == 0)
			printf("座位号: %2d (空)\n" , 
					pstr[i].number);
	}
	
 
	for (i = 0 ; i < n ; i++)
		printf("座位号: %-5d %-5s 名:%-20s 姓:%-20s\n" ,
				pstr[i].number ,
				pstr[i].selected ? "已预订" : "未预定" ,
				pstr[i].name ,
				pstr[i].s_name 
		      );
 
	return i ;
}
 
int sort_seat_list(seat * pstr , int n)
{
	int i,j;
	seat ** pstr_arr ;
	seat  * tmp ;
	int min ;
 
	pstr_arr = (seat **)calloc( n , sizeof(seat *));
 
	for ( i = 0 ; i < n ; i++)
		pstr_arr[i] = &pstr[i] ;
 
	for (i = 0 ; i < n - 1; i++)
	{
		
		for ( j = 0 ; j < n - 1 - i ; j++)
		{
			if (strcmp(pstr_arr[j]->name , pstr_arr[j + 1]->name) < 0)
			{
				tmp = pstr_arr[j] ;
				pstr_arr[j] = pstr_arr[j + 1] ;
				pstr_arr[j + 1] = tmp ;
			}
		}
		
 
	
 		min = i ;
 		for ( j = i + 1 ; j < n ; j++) 
 			if (strcmp(pstr_arr[min]->name , pstr_arr[j]->name) > 0)
 				min = j ;
 
		if (min != i)
		{
			tmp = pstr_arr[i] ;
			pstr_arr[i] = pstr_arr[min] ;
			pstr_arr[min] = tmp ;
		}
		
	}
 
	for (i = 0 ; i < n ; i++)
		printf("座位号: %-5d %-5s 名:%-20s 姓:%-20s\n" ,
				pstr_arr[i]->number ,
				pstr_arr[i]->selected ? "已预订" : "未预定" ,
				pstr_arr[i]->name ,
				pstr_arr[i]->s_name 
		      );
	free(pstr_arr);
 
}
 
int choice_seat(seat * pstr , int n)
{
	seat tmp ;
	char ch ;
	int flag = 0;
 
	puts("请输入您要挑选的座位号:");
	while (!scanf(" %d" , &tmp.number) || tmp.number < 1 || tmp.number > n || 
			(flag = pstr[tmp.number - 1].selected))
	{
		while (getchar() != '\n');
 
		if (flag)
		{
			puts("此座位已被预定,请重新选择座位:");
			flag = 0 ;
		}
		else
			puts("非法输入,请重新输入座位号:");
	}
	while (getchar() != '\n') ;
	tmp.selected = 1 ; 			//锁定此座位
 
	puts("请输入您的名:");
	while (!s_gets(tmp.name , NAME_LEN))
		puts("非法输入,请重新输入您的名:");
 
	puts("请输入您的姓:");
	while (!s_gets(tmp.s_name , NAME_LEN)) 
		puts("非法输入,请重新输入您的姓:");
 
	puts("======================================");
	printf("座位号: %d\n名:%s\n姓:%s\n" , tmp.number , tmp.name , tmp.s_name);
	puts("确认预约此座吗?(y/n):");
	while (!scanf(" %c" , &ch) || !isalpha(ch = tolower(ch))) ;
 
	if (ch == 'y')
	{
		pstr[tmp.number - 1] = tmp ;
		return 1 ; 
	}
	else
		return 0 ;
}
 
int delte_seat(seat * pstr , int n)
{
	int num ;
	int flag  = 0;
	char ch ;
 
	puts("请输入您要删除的座位号:");
	while (!scanf(" %d" , &num) || num < 1 || num > n || (flag = !pstr[num - 1].selected))
	{
		while (getchar() != '\n');
		
		if (flag)
		{
			puts("取消预约失败,此座位并未被预约");
			flag = 0 ;
		}
		else
			puts("非法输入,请重新输入要取消预约的座位号:");
	}
	while (getchar() != '\n') ;
 
	puts("======================================");
	printf("座位号: %d\n名:%s\n姓:%s\n" , pstr[num - 1].number , pstr[num - 1].name , pstr[num - 1].s_name);
	puts("确认此座取消预约吗?(y/n):");
	while (!scanf(" %c" , &ch) || !isalpha(ch = tolower(ch))) ;
 
	if (ch == 'y')
	{
		pstr[num - 1].selected = 0 ;
		pstr[num - 1].name[0] = '\0' ;
		pstr[num - 1].s_name[0] = '\0' ;
		return 1 ; 
	}
	else
		return 0 ;
}
 
char * s_gets(char * st , int n)
{
	char * ret_value = NULL ;
	char * find ;
 
	if (ret_value = fgets(st , n , stdin))
	{
		if (find = (strchr(st , '\n')))
			*find = '\0' ;
		else 
			while (getchar() != '\n') ;
	}
 
	return ret_value ;
}
