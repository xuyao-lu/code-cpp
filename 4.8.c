#include <stdio.h>
#define N 1.609/3.785
int main()
{
    double licheng;
    double qiyouliang;
    printf("请输入里程：");
    scanf("%lf",&licheng);
    printf("请输入汽油量：");
    scanf("%lf",&qiyouliang);

    printf("%.1lf\n",qiyouliang*3.758/(1.609*licheng)/100);
    printf("%.1lf\n",N*licheng/qiyouliang); 
       return 0;
}

