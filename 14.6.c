
# include <stdio.h>
# include <stdlib.h>
 
# define LEN 10
 
typedef struct 
{
	int num ;			//球员号
	char fname[LEN] ;		//名
	char lname[LEN] ;		//姓
	int play_times ;		//上场次数
	int hit_times ;			//击中次数
	int walk_times ;		//走垒数
	int rbi ;			//打点
	float hit_rate ;		//安打率
}player;
 
int main(void)
{
	FILE * fp ;
	player * pstr ;
	player tmp_player ;
	int count = 0 ;
	int flag  = 0 ;
    int i;
 
	//打开文件
	if ((fp = fopen("no2.txt" , "r")) == NULL)
	{
		puts("打开文件失败");
		exit(EXIT_FAILURE);
	}
 
	while (fscanf(fp , "%d %s %s %d %d %d %d\n" , &tmp_player.num ,
				tmp_player.fname , tmp_player.lname ,
				&tmp_player.play_times , &tmp_player.hit_times,
				&tmp_player.walk_times , &tmp_player.rbi) != EOF)
	{
		flag = 0 ;
		//先找此队员
		for ( i = 0 ; i < count ; i++)
		{
			if (pstr[i].num == tmp_player.num)
			{
				flag = 1 ;
				pstr[i].play_times += tmp_player.play_times ;
				pstr[i].hit_times += tmp_player.hit_times ;
				pstr[i].walk_times += tmp_player.walk_times ;
				pstr[i].rbi += tmp_player.rbi ;
				pstr[i].hit_rate = (double)pstr[i].hit_times / (double)pstr[i].play_times ;
			}
 
		}
 
		
		//未找到,添加新队员的信息
		if (!flag)
		{
			if (count == 0)
				pstr = (player *)malloc(sizeof(player) * ++count); 
			else
				pstr = (player *)realloc(pstr , sizeof(player) * ++count);
 
			pstr[count - 1] = tmp_player ;
			pstr[count - 1].hit_rate = (double)pstr[count - 1].hit_times / (double)pstr[count - 1].play_times ; 
		}
	}
 
	//打印每个球员的统计结果
	for (i = 0 ; i < count ; i++)
	{
		printf("%-10d %-10s %-10d %-10d %-10d %-10d %-10.d %10.2f%%\n" , 
				pstr[i].num ,
				pstr[i].fname ,
				pstr[i].lname ,
				pstr[i].play_times ,
				pstr[i].hit_times ,
				pstr[i].walk_times ,
				pstr[i].rbi ,
				pstr[i].hit_rate
				);
	}
 
	fclose(fp);		//关闭文件
	free(pstr);		//释放空间
 
	return 0 ;
}
