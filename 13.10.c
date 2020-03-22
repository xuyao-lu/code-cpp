#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
void main(void)
{
    char file_name[256];
    char content[256];
    int file_seek = 0;
    FILE *fp;

    printf("Enter the file name:");
    fscanf(stdin, "%s", file_name);
//  scanf("%s", file_name);

    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("Can't open %s file.\n", file_name);
    }

    while (1)
    {
        printf("Enter the location of file to print ( <0 to terminate) :");
        if (fscanf(stdin, "%d", &file_seek) != 1 || file_seek < 0)
        {
            break;
        }
        fseek(fp, file_seek, SEEK_SET);
        fgets(content, 256, fp);
      fscanf(fp, "%s", content);
     
     fprintf(stdout, "%s", content);
     fputs(content, stdin);
        printf("%s", content);
    }

    puts("Done");
    fclose(fp);

    return;
}
