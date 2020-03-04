#include <stdio.h>

int main()
{
    char ch;
    int count=0;

    printf("请输入一段话，以#结尾：\n");

    while((ch=getchar())!='#')
    {
        if(ch=='.')
        {
            putchar('!');
            count++;
        }
        else if(ch=='!')
        {
            putchar('!');
            putchar('!');
            count++;
        }
        else
        {
            putchar(ch);
        }
    }

    printf("\n一共替换了%d次.\n",count);
       return 0;
}

