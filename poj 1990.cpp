/*
˼·���Ȱ�val��С����������ÿ�η���һͷţ������״����bitcͳ�Ƶ�ǰţ���ţ�ĸ�����
����״����bitsͳ�Ƶ�ǰţ�������x����ĺͣ���ǰ��iͷţxΪpos,�ڼ�����ߵ�x��ʱ����
pos*���ţ�ĸ���-���ţx�ܺͣ������ұߵ�x�ĺ�ʱ��totalΪ��ǰ����ţx����ͣ���
��total-���ţx�ĺͣ��õ��ұ�����ţx�ĺͣ��ټ�ȥ��i-���ţ�ĸ�����* pos�õ��ұ߽����
������������ۼ���͡�
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
	while(i<=xmax)//ע�����ﲻ��д��n�����˰���
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