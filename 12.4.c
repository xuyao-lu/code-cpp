#include <stdio.h>
#include <stdlib.h>
 
void fun()
{
    static num = 0;
    printf("%d\n", ++num);
}
 
int main(void)
{
    int n = 0;
    scanf("%d", &n);
    while(n--)
    {
        fun();
    }
    return 0;
}
