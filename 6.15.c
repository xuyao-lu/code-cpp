#include <stdio.h>
#include <string.h>
int main()
{
    char arr[300];
    scanf("%s",arr);
    int k=strlen(arr);
    for(int j=k-1;j>=0;j--)
    {
        printf("%c",arr[j]);
    }
    printf("\n");
       return 0;
}

