#include<stdio.h>
#include<string.h>
char a[1003][20];
int main()
{
 int n,i,j,sta[1003],max,color;
 while(scanf("%d",&n)!=EOF&&n!=0)
 {
  getchar();
  max=0;
  memset(sta,1,sizeof(sta));
  for(i=1;i<=n;i++)
  {
   gets(a[i]);
   for(j=1;j<i;j++)
   {
    if(!strcmp(a[j],a[i]))
    {
     sta[j]++;
     break;
    }
   }
  }
  for(i=1;i<=n;i++)
  {
   if(sta[i]!=1&&sta[i]>max)
   {
    max=sta[i];
    color=i;
   }
  }
   puts(a[color]);
 }
 return 0;
}