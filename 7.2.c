#include <stdio.h>

int main()
{
    char ch;
    int number=0;

    printf("请输入，以#结尾：\n");

    while((ch=getchar())!='#')
    {
        printf("%c--%-5d",ch,ch);
        number++;
        if(number%8==0)
        {
            printf("\n");
        }

    }
    printf("\n");
       return 0;
}

