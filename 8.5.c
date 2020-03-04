#include <stdio.h>
#include <ctype.h>
int main()
{
    int guess=50,upper=100,lower=0;
    char ch;

    printf("Pick an integer from 1 to 100. I will try to guess it.\nRespond with a y if my guess if right and with \nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n",guess);

    while((ch=getchar()))
    {
        if(!isalpha(ch))
            continue;
        while(getchar()!='\n')
            ;
        if(tolower(ch)=='y')
            break;

        printf("the number you cchosen is bigger or smaller than i guest?(b/s):");

        while((ch=getchar()))
        {
            if(!isalpha(ch))
                continue;

            while(getchar()!='\n')
                ;
            switch(tolower(ch))
            {
            case 'b':upper=guess;
                     guess-=((upper-lower)/2);
                     break;
            case 's':
                     lower=guess;
                     guess+=((upper-lower)/2);
                     break;
            default:
                     printf("Invalid cchoice ,the number you chosen is bigger or smaller than i guest?(b/s):");
                     continue;
            }
            break;
        }
        printf("it is %d?(y/n)\n",guess);
    }
    printf("the number is %d.\n",guess);
       return 0;
}

