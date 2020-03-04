#include <stdio.h>
#include <ctype.h>

int main()
{
    int last,now;
    int nu_char=0,nu_word=0;

    while((now=getchar())!=EOF)
    {
        if(isalpha(now))
            nu_char++;
        else if(isalpha(last))
            nu_word++;
        last=now;
    }

    printf("一共有%d个单词，有%d个字符，平均每个单词有%.2lf个字母。\n",nu_word,nu_char,(double)nu_char,(double)nu_word);
       return 0;
}

