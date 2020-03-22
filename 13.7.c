#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>


void main(void)
{
    FILE *file1, *file2;
    char file_name1[128];
    char file_name2[128];
    char buf1[256] = { 0 };
    char buf2[256] = { 0 };

    printf("Enter the first file name:");
    gets_s(file_name1, 128);

    printf("Enter the second file name:");
    gets_s(file_name2, 128);

    if ((file1 = fopen(file_name1, "r")) == NULL)
    {
        printf("Can't open %s\n", file_name1);
    }
    if ((file2 = fopen(file_name2, "r")) == NULL)
    {
        printf("Can't open %s\n", file_name2);
    }

    while ((feof(file1) == 0) || (feof(file2) == 0))
    {
        if (fgets(buf1, 256, file1) != NULL)
        {
            int length = strlen(buf1);
            
            fputs(buf1, stdout);
        }
        if (fgets(buf2, 256, file2) != NULL)
        {
            fputs(buf2, stdout);
        }
    }

    return;
}
