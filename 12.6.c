#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int n;
    int i,j;
    for (i = 0; i < 10; ++i)
    {
        n = 1000;
        srand(i);
        int *p = calloc(11, sizeof(int));
        while(n--)
        {
            p[rand() % 11 + 1]++;
        }
        for (j = 1; j < 11; ++j) {
            printf("%d ", p[j]);
        }
        putchar('\n');
        free(p);
    }
 
}
