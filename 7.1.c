#include <stdio.h>
#define kg ' '
#define hh '\n'
int main(void)
{
    char ch;
    int kongge=0,huanhang=0,qita=0;

    printf("请输入，以#字符结尾：");

    while((ch=getchar())!='#')
    {
        if(ch==kg)
        {
            kongge++;
        }
        else if(ch==hh)
        {
            huanhang++;
        }
        else
        {
            qita++;
        }
    }

    printf("这段话中有%d个空格，有%d个换行符，有%d个其他字符\n",kongge,huanhang,qita);

       return 0;
}

