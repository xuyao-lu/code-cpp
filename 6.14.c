#include <stdio.h>
#define N 8
int main()
{
    double arr1[N],arr2[N];
    printf("请输入8个数：");
    for(int i=0;i<N;i++)
        scanf("%lf",&arr1[i]);
    arr2[0]=arr1[0];
    for(int j=1;j<N;j++)
    {
        arr2[j]=arr1[j]+arr2[j-1];
    }

    for(int i=0;i<N;i++)
    {
        printf("%10lf",arr1[i]);
    }
    printf("\n");
    for(int j=0;j<N;j++)
    {
        printf("%10lf",arr2[j]);
    }
       return 0;
}

