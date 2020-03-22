# include <stdio.h>
# include <ctype.h>
# include <windows.h>
 
# define FLIGHT_COUNT 4
# define SEAT_COUNT 12
# define NAME_LEN 50 
 
typedef struct 
{
	int number ;
	int selected ;
	char name[NAME_LEN] ;
	char s_name[NAME_LEN];
}seat;
 
 
int initialize_airline(seat * pstr , int r , int c);
void print_menu(int n);
char choice_menu(int n);
int switch_menu(int choice , seat * pstr);
int empty_seat_count(const seat * pstr , int n);
int show_seat_list(const seat * pstr , int n);
int sort_seat_list(seat * pstr , int n);
int choice_seat(seat * pstr , int n);
int delte_seat(seat * pstr , int n);
char * s_gets(char * st , int n);
void print_flight(void);
char choice_flight(void);
int flight_switch(char ch);
 
int main(void)
{
	seat airline[FLIGHT_COUNT][SEAT_COUNT] ;
	int num ;
 
	initialize_airline(*airline, FLIGHT_COUNT ,SEAT_COUNT);			//初始化座位
 
	/*
	for (int i = 0 ; i < FLIGHT_COUNT ; i++)
	{
		for (int j = 0 ; j < SEAT_COUNT ; j++)
			printf("%d %d %s %s\n" , airline[i][j].number , airline[i][j].selected ,
					airline[i][j].name , airline[i][j].s_name);
		if ((i + 1 % 2) == 0)
		putchar('\n');
	}
	*/
 
	while (num = flight_switch(choice_flight()))
	{
		if (num > 0)
			while (switch_menu(choice_menu(num - 1) , airline[num - 1])) ;
	}
 
	puts("再见,欢迎下次乘坐.祝您生活愉快");
 
	return 0 ;
}
 
int initialize_airline(seat * pstr , int r , int c)
{
	int i ;
	int j ;
 
	for (i = 0 ; i < r ; i++)
	{
		for (j = 0 ; j < c ; j++)
		{
			(pstr + (i * c + j))->number = j + 1 ;
			(pstr + (i * c + j))->selected = 0 ;
			(pstr + (i * c + j))->name[0] = '\0' ;
			(pstr + (i * c + j))->s_name[0] = '\0' ;
		}
	}
 
	return ((i * j) == (r * c) ? (i * j) : 0) ;
}
 
int flight_switch(char ch)
{
	switch (ch)
	{
		case 'a' :
			//厦航102
			return 1 ;
			break ;
		case 'b' :
			//国航311
			return 2 ;
			break ;
		case 'c' :
			//马航444
			return 3 ;
			break ;
		case 'd' :
			//南航519
			return 4 ;
			break ;
		case 'e' :
			//退出
			return 0 ;
			break ;
		default :
			//错误
			puts("无效选择,请重新选择");
			system("pause");
			return -1 ;
			break ;
	}
}
 
char choice_menu(int n)
{
	char ch ;
 
	print_menu(n);
	while (!scanf(" %c" , &ch) || !isalpha(ch))
	{
		while (getchar() != '\n') ;
		puts("输入非法,请重新输入");
	}
 
	while (getchar() != '\n') ;
 
	return tolower(ch) ;
}
 
void print_menu(int n)
{
	int i;
	static const char * menu[] = 
	{
		"请选择所要执行的操作:",
		"a) 显示剩余未预定的座位数",
		"b) 显示座位列表",
		"c) 按首字母排序显示座位列表",
		"d) 预定座位",
		"e) 取消预定座位",
		"f) 返回上一级菜单"
	};
 
	static const char * flight[] = 
	{
		"厦航102" ,
		"国航311" ,
		"马航444" ,
		"南航519" ,
	};
 
	system("cls");
	printf("您选择的是[%s]航班\n", flight[n]);
	puts("-------------------------------------------------");
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
	/*
	for (i = 0 ; i < n ; i++)
	{
		if (pstr[i].selected == 0)
			printf("座位号: %2d (空)\n" , 
					pstr[i].number);
	}
	*/
 
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
	seat ** pstr_arr ;
	seat  * tmp ;
	int min ;
	int i,j;
 
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
 
	puts("请输入您要删除的座位号:(0 退出)");
	while (!scanf(" %d" , &num) || num < 1 || num > n || (flag = !pstr[num - 1].selected))
	{
		while (getchar() != '\n');
		
		if (flag)
		{
			puts("取消预约失败,此座位并未被预约");
			flag = 0 ;
		}
		else if (num == 0) 			//终止取消预约操作
			return 0 ;
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
 
 
void print_flight(void)
{
	int i;
	static const char * flight[] = 
	{
		"请选择一驾航班:" ,
		"a) 厦航102" ,
		"b) 国航311" ,
		"c) 马航444" ,
		"d) 南航519" ,
		"e) 退出"
	};
 
	system("cls");
 
	for ( i = 0 ; i < sizeof(flight) / sizeof(flight[0]) ; i++)
	{
		puts(flight[i]);
	}
}
 
char choice_flight(void)
{
	int ch ;
 
	print_flight() ;
	while (!scanf(" %c" , &ch) || !isalpha(ch))
	{
		while (getchar() != '\n') ;
		puts("非法输入,请重新选择");
	}
 
	return tolower(ch) ;
}
