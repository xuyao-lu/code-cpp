#include <stdio.h>

int main()
{
    char arr[30];
    for(int i=0;i<26;i++)
    {
        arr[i]='a'+i;
    }
    for(int i=0;i<26;i++)
    {
        printf("%c",arr[i]);

    }
    printf("\n");
       return 0;
}

