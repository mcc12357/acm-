

#include<stdio.h>
#include<string.h>
int result[110][110];
char str[110];
bool p(char x,char y)
{
	return(x=='('&&y==')'||x=='['&&y==']');
}
int dp(int x=0,int y=strlen(str))//一般都用左闭右开区间
{
	if(x==y)
	{
		result[x][y]=0;//这句话不要忘记
		return(0);
	}
	int i,f=0,min=1000;
	for(i=x+1;i<y;i++)
	{
		if(p(str[x],str[i]))
		{
			if(result[x+1][i]==-1)result[x+1][i]=dp(x+1,i);
			if(result[i+1][y]==-1)result[i+1][y]=dp(i+1,y);
			result[x][y]=result[x+1][i]+result[i+1][y];
			if(min>result[x][y])min=result[x][y];
			f=1;
		}
	}
	result[x][y]=min;
	if(f==0)result[x][y]=1+dp(x+1,y);
	return(result[x][y]);
}
int main()
{
//	freopen("in.txt","r",stdin);  //这句话不要忘记去掉
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(result,-1,sizeof(result));
		scanf("%s",str);
		printf("%d\n",dp());
	}
	return(0);
}