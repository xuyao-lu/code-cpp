#include <stdio.h>

int main()
{
    char ch;
    int i=0;

    while((ch=getchar())!=EOF)
        i++;

    printf("有%d个字符。\n",i);
       return 0;
}

