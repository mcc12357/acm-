#include<stdio.h>
#include<string.h>
int main()
{
char a[22];//������ַ�������ȡ��
int k;
while(scanf("%s %d",a,&k)!=EOF)
{
int i,j,t;
int len=strlen(a);
char flag;//�����ַ����м����
for(i=0; i<len&&k!=0; i++)//ע��k!=0
{
t=i;
for(j=i+1; j<=i+k&&j<len; j++)
if(a[t]<a[j])
t=j;
for(j=t; j>i; j--)
{
flag=a[j];//̰�Ľ���
a[j]=a[j-1];
a[j-1]=flag;
}
k-=t-i;//ʣ����ƶ�����
}
printf("%s\n",a);
}
return 0;
}