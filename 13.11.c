#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
void main(int argc, char **argv)
{
    char content[256];
    FILE *fp;

    if (argc != 3)
    {
        printf("Usage: %s <string> <file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open file %s.\n", argv[2]);
    }
    while ((fgets(content, 256, fp)) != NULL)
    {
        if (strstr(content, argv[1]) != NULL)
        {
            fputs(content, stdout);
        }
    }
}
