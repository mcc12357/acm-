#include <time.h>
#include <stdio.h>
int main()
{
        clock_t start,end;
        start=clock();
        //...........����
        end=clock();
        printf("The different is %6.3f\n",(double)(end-start));//��λ�Ǻ��룬/CLOCKS_PER_SEC����/1000���ת������
        return 0;
}