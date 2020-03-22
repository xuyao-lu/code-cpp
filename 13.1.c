#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>



int main(void)
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    char file_name[256];

    printf("Enter the file name: ");
    scanf("%s", file_name, 256);

    if ((fp = fopen(file_name, "r")) == NULL) 
    {                                         
        printf("Can't not open %s\n", file_name);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", file_name, count);

    return 0;
}
