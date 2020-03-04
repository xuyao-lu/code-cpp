#include <stdio.h>

void chline (char ch,int i,int j);

int main()
{
    char ch;
    int row,column;

    printf("Please enter a character:");
    ch=getchar();
    printf("Please enter the number of rows and columns:");
    scanf("%d %d",&row,&column);

    chline(ch,column,row);

       return 0;
}

void chline(char ch,int i,int j)
{
    int row,column;

    for(row=0;row<j;row++)
    {
        for(column=0;column<i;column++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}

