#include <stdio.h>

int main()
{
    char arr='F';
    char start;
    char end;
    for(end=arr;end>='A';end--)
    {
        for(start=arr;start>=end;start--)
            printf("%c",start);
        printf("\n");
    }
       return 0;
}

