#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main()
{
    char ch;

    while((ch=get_first())!=EOF)
        putchar(ch);

       return 0;
}
char get_first(void)
{
    int ch;

    while(isblank(ch=getchar()))
        ;
    while(getchar()!='\n')
        ;
    return ch;
}
