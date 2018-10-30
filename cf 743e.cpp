#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int f[1010][260];//f[i][mask]表示进行到第i个数，当前使用过的数状态为mask的最长子序列长度
int lim = (1<<8) - 1;
int seq[1010];//存放原数列
int ord[1010];//ord[i]表示原序列的第i个元素第几次出现
int pos[10][1010];//pos[i][j]表示元素i出现j次的在原序列中的下标
int cnt[10];//cnt[i]表示i出现的次数
int tmp,ans,n;
int max(int x,int y)
{
	if(x<y) return y;
	return x;
}
bool judge(int x)
{
	tmp = 0;
	memset(f,0xef,sizeof(f));//初始化为负无穷
	f[0][0] = 0;//进行到第0个数并且当前状态为00000000的最大子序列长度为0
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=lim;j++)
		{
			f[i][j] = f[i-1][j];//不取当前第i个数得到的最长长度
			if(j&(1<<seq[i]))//取当前第i个数的状态
			{
				int now = ord[i];
				//当前数取x个
				if(x>0&&now-x>=0)//x==0的情况不会更新f[i][j]值,当前数seq[i]出现次数大于等于所需x个，才可以取seq[i]
				{
					//pos[i][now-x+1]即为从不算当前数从当前数往前已经取了x-1个当前数的最右边的位置，即这x-1个当前数是必须连续取得子序列，此位置以前的不管
					//j^(1<<seq[i])即为其他数取不取与当前状态一样但j没有取的状态
					f[i][j] = max(f[i][j],f[pos[seq[i]][now-x+1]-1][j^(1<<seq[i])]+x);
				}
				//当前数取(x+1)个
				if(now-x>=1)
				{
					f[i][j] = max(f[i][j],f[pos[seq[i]][now-x]-1][j^(1<<seq[i])]+x+1);
				}
			}
		}
	}
	if(x==0)
	{
		for(i=0;i<=lim;i++) tmp = max(tmp,f[n][i]);//因为x为0时不一定每个数都要取
	}
	else tmp = f[n][lim];//x>=1时每个数都必须取，x==1时也必须就满足，否则当某个数取x+1个时，如果有一个数没有取就不满足题目条件
	return tmp>0;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&seq[i]);
		seq[i]--;//将1-8对应于0-7，便于后面位运算，否则后面位运算就是移seq[i]-1位
	}
	for(i=1;i<=n;i++)
	{
		ord[i] = ++cnt[seq[i]];
		pos[seq[i]][cnt[seq[i]]] = i;
	}
	int l = 0,r = n / 8;
	while(r>=l)
	{
		int mid = (l + r) >> 1;
		if(judge(mid))
		{
			ans = tmp;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d\n",ans);
}