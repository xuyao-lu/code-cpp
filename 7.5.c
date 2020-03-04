#include <stdio.h>

int main()
{
    char ch;
    int count=0;

    printf("请输入一段话，以#结尾：\n");

    while((ch=getchar())!='#')
    {
    switch(ch)
    {
    case '.':{putchar('!');
             count++;
             break;
             }
    case '!':{
                 putchar('!');
                 putchar('!');
                 count++;
                 break;
             }
    default:putchar(ch);

    }
    }
    printf("\n一共替换了%d次\n",count);
       return 0;
}

