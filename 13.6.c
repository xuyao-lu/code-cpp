#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>

#define LEN 40
void main(void)
{
    FILE *in, *out;
    int ch;
    char out_file[LEN];
    char in_file[LEN];
    int count = 0;

    printf("Enter the file name:");
    gets_s(in_file, LEN);

    if ((in = fopen(in_file, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file\"%s\"", in_file);
        exit(EXIT_FAILURE);
    }

    strncpy(out_file, in_file, LEN-5);
    out_file[LEN - 5] = '\0';
    strcat(out_file, ".red");

    if ((out = fopen(out_file, "w")) == NULL)
    {
        fprintf(stderr, "Can't creat output file.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out);
    }

    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
    }

    return;

}
