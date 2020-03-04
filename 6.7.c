#include <stdio.h>
#include <string.h>
int main()
{
    char n[1000];
    scanf("%s",&n);
    int m;
    m=strlen(n);
    char k[1000];
    for(int i=0;i<m;i++)
    {
        k[i]=n[m-i-1];
    }
    for(int i=0;i<=m;i++)
    printf("%c",k[i]);

    printf("\n");

       return 0;
}

