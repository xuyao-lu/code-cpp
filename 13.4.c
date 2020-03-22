#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>


void main(int argc, char **argv)
{
    FILE *fp;
    int i;
    char a[256] = { 0 };
    for (i = 1; i < argc; i++)
    {
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Can't open file %s as read!\n", argv[i]);
        }

        printf("%s:\n", argv[i]);
        while (fgets(a, 256, fp) != NULL)
        {
            fputs(a, stdout);
        }

        printf("\n");
    }

    printf("Done!\n");

    return ;
}
