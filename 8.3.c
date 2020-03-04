#include <stdio.h>
#include <ctype.h>
int main()
{
    char ch;
    int un_upper=0,un_lower=0,un_other=0;

    while((ch=getchar())!=EOF)
    {
        if(isupper(ch))
            un_upper++;
        else if(islower(ch))
            un_lower++;
        else
            un_other++;
    }

    printf("大写字母有%d，小写字母有%d个，非字母字符有%d个。\n",un_upper,un_lower,un_other);

       return 0;
}

