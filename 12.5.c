#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void sort(int a[], int c, int d)
{
    int s = c;
    int e = d;
    if(s < e)
    {
        int t = a[s];
        while (s < e) {
            while (s < e && a[e] <= t) {
                e--;
            }
            a[s] = a[e];
            while (s < e && a[s] >= t) {
                s++;
            }
            a[e] = a[s];
        }
        a[s] = t;
        sort(a, c, s - 1);
    sort(a, s + 1, d);
    }
}
 
int main()
{
    srand((unsigned int)time(0));
    int a[101];
    int i;
    for(i = 0; i < 100; i++)
    {
        a[i] = rand() % 11 + 1;
    }
    sort(a, 0, 99);
    for(i = 0; i < 100; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
