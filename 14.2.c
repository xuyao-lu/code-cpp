#include<stdio.h>
#include<string.h>
#define N_MONTH  12

typedef struct MONTH_INFO
{
    char month[4];
    int month_days;
    int month_number;
} ST_MONTH_INFO;

const ST_MONTH_INFO info[N_MONTH] = {
    {"Jan", 31, 1},
    {"Feb", 28, 2},
    {"Mar", 31, 3},
    {"Apr", 30, 4},
    {"May", 31, 5},
    {"Jun", 30, 6},
    {"Jul", 31, 7},
    {"Aug", 31, 8},
    {"Sep", 30, 9},
    {"Oct", 31, 10},
    {"Nov", 30, 11},
    {"Dec", 31, 12}
};

int  main(void)
{
    char month[4];
    int days = 0;
    int total_days = 0;
    int find=0;
    int i = 0;

    while (find == 0)
    {
        total_days = 0;
        printf("Enter the abbreviation of month:");
        fgets(month, 4, stdin);

        for (i = 0; i < N_MONTH; i++)
        {
            total_days += info[i].month_days;
            if (strcmp(month, info[i].month) == 0)
            {
                find = 1;
                break;
            }
        }

        if (find == 1)
            printf("There are %d days till %s\n", total_days, month);
        else
            printf("The month of addreviation is not found! Enter again.\n");
    }

    find = 0;
    while (find == 0)
    {
        printf("Enter the days of month:");
        scanf("%d", &days);
        if (days < info[i].month_days)
        {
            total_days += days;
            find = 1;
            printf("There %d days till %s %d\n", total_days, month, days);
        }
        else
            printf("The day of month is not found! Enter again.\n");
    }

    return 0 ;
}

