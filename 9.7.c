#include <stdio.h>
#include <ctype.h>

int position(char ch);

int main()
{
    char ch;
    int p;

    printf("Please enter some text.(end with EOF)\n");

    while((ch=getchar())!=EOF)
    {
        p=position(ch);
        if(p!=-1)
            printf("The alphabet position of %c is %d\n",ch,p);
        else
            printf("%c is not a letter\n",ch);
    }

       return 0;
}

int position(char ch)
{
    if(isupper(ch))
        return ch-'A'+1;
    else if(islower(ch))
        return ch-'a'+1;
    else
        return -1;
}

