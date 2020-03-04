#include <stdio.h>

int main()
{
    int day;
    const int week=7;
    printf("请输入天数：");
    while (scanf("%d",&day)&&day>0)
    printf("%d day are %d weeks, %d day.\n",day,day/week,day%week);
       return 0;
}

