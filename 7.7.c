#include <stdio.h>
#define BASICS 10
int main()
{
    int hour,zonge,sum,shuijin,jingshouru;

    printf("请输入一周工作的小时数：\n");
    scanf("%d",&hour);

    if(hour<=40)
    {
        sum=hour*BASICS;

        if(zonge<=30)
        {
            shuijin=0;
            jingshouru=zonge;
            printf("您的工资总数为%d，税金为%d，净收入为%dd。\n",zonge,shuijin,jingshouru);
        }
        else
        {
            shuijin=300*0.15+(zonge-300)*0.2;
            jingshouru=zonge-shuijin;
            printf("您的工资总数为%d，税金为%d，净收入为%dd。\n",zonge,shuijin,jingshouru);
        }
    }
    else
    {
        zonge=400+BASICS*(hour-40)*1.5;
        if(zonge<=450)
        {
            shuijin=300*0.15+(zonge-300)*0.2;
            jingshouru=zonge-shuijin;
            printf("您的工资总数为%d，税金为%d，净收入为%dd。\n",zonge,shuijin,jingshouru);
        }
        else
        {
            shuijin=300*0.15+150*0.2+(zonge-450)*0.25;
            jingshouru=zonge-shuijin;
            printf("您的工资总数为%d，税金为%d，净收入为%dd。\n",zonge,shuijin,jingshouru);
        }
    }
       return 0;
}

