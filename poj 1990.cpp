/*
思路：先按val从小到大排完序，每次放入一头牛，用树状数组bitc统计当前牛左边牛的个数，
用树状数组bits统计当前牛左边所有x坐标的和，当前第i头牛x为pos,在计算左边的x和时，用
pos*左边牛的个数-左边牛x总和，计算右边的x的和时，total为当前所有牛x坐标和，用
（total-左边牛x的和）得到右边所有牛x的和，再减去（i-左边牛的个数）* pos得到右边结果，
左右两边相加累计求和。
*/
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
typedef long long ll;
int n;
struct Cow
{
	int x;
	int val;
}cow[20005];
ll bitc[20005],bits[20005];
int xmax = 20005;
bool cmp(Cow a,Cow b)
{
	return a.val<b.val;
}
void add(int i,ll x,ll *bit)
{
	while(i<=xmax)//注意这里不能写成n，查了半天
	{
		bit[i] += x;
		i += i & -i;
	}
}
ll sum(int i,ll *bit)
{
	ll ret = 0;
	while(i>0)
	{
		ret += bit[i];
		i -= i & -i;
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d %d",&cow[i].val,&cow[i].x);
	sort(cow+1,cow+1+n,cmp);
	ll total = 0;
	ll ans = 0;
	for(i=1;i<=n;i++)
	{
		total += cow[i].x;
		int pos = cow[i].x;
		add(pos,1,bitc);
		add(pos,pos,bits);
		ll count = sum(pos,bitc);
		ll dis = sum(pos,bits);
		ans += cow[i].val*(count*pos-dis+total-dis-(i-count)*pos);
	}
	printf("%lld\n",ans);

}