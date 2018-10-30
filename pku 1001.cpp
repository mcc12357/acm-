#include <time.h>
#include <stdio.h>
int main()
{
        clock_t start,end;
        start=clock();
        //...........程序
        end=clock();
        printf("The different is %6.3f\n",(double)(end-start));//单位是毫秒，/CLOCKS_PER_SEC或者/1000或可转换成秒
        return 0;
}