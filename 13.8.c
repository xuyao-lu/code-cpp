#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>

void main(int argc, char **argv)
{
	int i;
    char find_ch = 0;
    char ch = 0;
    char input[256] = { 0 };
    int repeat_time = 0;
    FILE *fp;

    if (argc < 2)
    {
        printf("Usage: %s <character> [file_name1 ....]", argv[0]);
        return;
    }

    find_ch = argv[1][0];
    if (argc == 2)
    {
        printf("Enter the string you wanted to analysize: ");
        gets_s(input, 256);
        int input_length = strlen(input);
        for (i = 0; i < input_length; i++)
        {
            if (find_ch == input[i])
            {
                repeat_time++;
            }
        }

        printf("In string \"%s\", %c have appeared %d times!\n", input, find_ch, repeat_time);
    }
    else
    {
        for ( i = 2; i < argc; i++)
        {
            repeat_time = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                printf("Can't open %s\n", argv[i]);
                continue;
            }

            while ((ch = fgetc(fp)) != EOF)
            {
                if (ch == find_ch)
                {
                    repeat_time++;
                }
            }
            printf("In file %s, %c have appeared %d time!\n", argv[i], find_ch, repeat_time);
        }
    }

    return;
}
