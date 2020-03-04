#include <stdio.h>

int main()
{
    char arr='A';
    for (int i=0;i<6;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%c",arr++);
        }
        printf("\n");
    }
       return 0;
}

