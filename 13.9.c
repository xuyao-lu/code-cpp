#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>


#define MAX 41
void p13_9(void)
{
    FILE *fp;
    char words[MAX];
    int n_word = 0;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open\"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
    {
        n_word++;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the begining of a line to terminate.");

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%d:%s\n", ++n_word, words);
    }
    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
    {
        puts(words);
    }
    puts("Done");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error closing file\n");
    }

    return;
}

