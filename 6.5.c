#include <stdio.h>
#include<stdlib.h>
int  main()
{ 
    char n;
    scanf("%c",&n);
  
    int i=65 , j ;
    for(;i<=n;i++)
    {   
        for (int m=0;m<=n-1-i;m++)
            printf(" ");
        for(j=65;j<=i;j++)
            printf("%c",j);
        for(j=i-1;j>=65;j--)
            printf("%c",j);
        printf("\n");
    }   
 }
