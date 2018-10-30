#include <stdio.h>  
#include <string.h>  
#include <math.h>  
  
#define MAX 100001  
  
int pie[MAX][12];   /*pie[i][j]表示在i时刻落在j点的馅饼数量*/  
  
int MaxOf2(int a, int b){  
    return (a > b) ? a : b;  
}  
  
int MaxOf3(int a, int b, int c){  
    int max = (a > b) ? a : b;  
    return (max > c) ? max : c;  
}  
  
int MaxNumOfPie(int max_time){  
    int i, j, max;  
    for (i = max_time - 1; i >= 0; --i){  
        pie[i][0] = MaxOf2(pie[i+1][0], pie[i+1][1]) + pie[i][0];  
        /*printf("%d ", pie[i][0]);*/  
        for (j = 1; j < 10; ++j){  
            pie[i][j] = MaxOf3(pie[i+1][j-1], pie[i+1][j], pie[i+1][j+1]) + pie[i][j];  
            /*printf ("%d ", pie[i][j]);*/  
        }  
        pie[i][10] = MaxOf2(pie[i+1][10], pie[i+1][9]) + pie[i][10];  
        /*printf ("%d\n", pie[i][10]);*/  
    }  
    return pie[0][5];  
}  
  
int main(void){  
    int n;  
    int i;  
    int time;  
    int location;  
    int max_time;  
  
    while (scanf("%d", &n) != EOF && n != 0){  
        memset(pie, 0, sizeof(pie));  
        max_time = -1;  
        for (i=1; i<=n; ++i){  
            scanf ("%d%d", &location, &time);  
            ++pie[time][location];  
            if (max_time < time)  
                max_time = time;  
        }  
        printf ("%d\n", MaxNumOfPie(max_time));  
    }  
  
    return 0;  
}  
