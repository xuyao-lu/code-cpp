#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice(int sets, int dice, int sides);	
int roll1(int sides);					




int main(void)
{
	int dice;					
	int sides;					
	int status;			        	
	int sets;					
	srand((unsigned int)time(0));			
 
	printf("Enter the number of sets; enrer q to stop: ");
	while (status = scanf_s("%d", &sets) == 1 && sets > 0)
	{
	    puts("How many sides and how many dice?");
	    while (status = scanf_s("%d %d", &sides, &dice) != 2)
	    {
		if (status == EOF)
			break;			
		else
		{
		    if (status == 1 || status == 0)
		    {
	           	puts("You should have entered an integer.");
			puts(" Let's begin again.\n");
		    }
        	    while (getchar() != '\n')		
		    {
			continue;
	            }
        	    puts("How many sides and how many dice?");
	        }
	    }
            roll_n_dice(sets, dice, sides);		
	    printf("How many sets? Enter q to stop: ");
	}
 
	if (status == 0)			
	{
	    puts("The sets entered error. Exit!");
	}
 
	return 0;
}


int roll1(int sides)
{
    int roll;
 
    roll = rand() % sides + 1;			
 
    return roll;
}




void roll_dice(int sets, int dice, int sides)
{
	int d, i;				
	int total = 0;				
 
	if (sides < 2)					
	{
	    puts("Need at least 2 sides.\n");
	    return;
	}
	if (dice < 1)					
	{
	    puts("Need at least 1 die.\n");
	    return;
	}
 

	printf("Here are %d setsof %d %d-sided throw.\n",
		sets, dice, sides);
 
	for (i = 0; i < sets; i++)			
	{
		for (d = 0; d < dice; d++)
		{
		    total += rollem(sides);		
		}
		printf("%d ", total);
		if (i == 14)			        
		{					
		    putchar('\n');		
		}
		total = 0;				
	}
	putchar('\n');
 
	return;
}

