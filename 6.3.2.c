#include <stdio.h>

int main()
{
    char arr='A';
    for(char i=arr;i<='F';i++)
    {
        for(char j=arr;j<=i;j++)
        {
            printf("%c",j);
        }
        printf("\n");
    }
       return 0;
}

