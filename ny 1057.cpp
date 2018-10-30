#include<stdio.h>
#include<string.h>
int main()
{
char a[22];//定义成字符串便于取长
int k;
while(scanf("%s %d",a,&k)!=EOF)
{
int i,j,t;
int len=strlen(a);
char flag;//单个字符做中间变量
for(i=0; i<len&&k!=0; i++)//注意k!=0
{
t=i;
for(j=i+1; j<=i+k&&j<len; j++)
if(a[t]<a[j])
t=j;
for(j=t; j>i; j--)
{
flag=a[j];//贪心交换
a[j]=a[j-1];
a[j-1]=flag;
}
k-=t-i;//剩余可移动次数
}
printf("%s\n",a);
}
return 0;
}