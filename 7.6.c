#include <stdio.h>

int main()
{
    char before,now;
    int count=0;

    printf("请输入一段话，并以#结尾：\n");
    
    while((now=getchar())!='#')
    {
        if(before=='e'&&now=='i')
        {
            count++;
        }
        before=now;
    }

    printf("ei出现的次数为%d。\n",count);

       return 0;
}

