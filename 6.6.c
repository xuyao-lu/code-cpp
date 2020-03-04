#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=n;i<=m;i++)
    {
        printf("%d %d %d\n",i,i*i,i*i*i);
    }
       return 0;
}

