#include <stdio.h>

int main()
{
    double bei;
    printf("请输入杯数：");
        scanf("%lf",&bei);

        printf("等于%lf品脱\n",bei/2);
        printf("等于%lf盎司\n",bei*8);
        printf("等于%lf大汤勺\n",bei*16);
        printf("等于%lf茶勺\n",bei*48);
       return 0;
}


//整型会在除法的时候将小数点的数字省略，这样的计算方法不等价。
//本身杯数也有可能是小数，那么更容易不等价。
