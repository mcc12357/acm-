#include<iostream>
using namespace std;
#include<string.h>
//int n;
//int *x1 = new int[100000001],*x2 = new int[100000001],*y1 = new int[100000001],*y2 = new int[100000001],*res = new int[100000001];
int x1[10001],y1[10001],x2[10001],y2[10001],res[10001],n;
int dp(int i)
{
	int j;
	if(res[i]!=1) return res[i];
	if(i==n-1) return 0;
	for(j=i+1;j<n;j++)
	{
		if((((x1[j]>=x1[i]&&y2[j]<=y2[i])&&!(x1[j]==x1[i]&&y2[j]==y2[i]))&&((x1[j]<=x2[i]&&y2[j]<=y2[i])&&!(x1[j]==x2[i]&&y2[j]==y2[i]))&&((x1[j]>=x1[i]&&y2[j]>=y1[i])&&!(x1[j]==x1[i]&&y2[j]==y1[i])))||
			(((x1[j]>=x1[i]&&y1[j]<=y2[i])&&!(x1[j]==x1[i]&&y1[j]==y2[i]))&&((x1[j]<=x2[i]&&y1[j]<=y2[i])&&!(x1[j]==x2[i]&&y1[j]==y2[i]))&&((x1[j]>=x1[i]&&y1[j]>=y1[i])&&!(x1[j]==x1[i]&&y1[j]==y1[i])))||
			(((x2[j]>=x1[i]&&y2[j]<=y2[i])&&!(x2[j]==x1[i]&&y2[j]==y2[i]))&&((x2[j]<=x2[i]&&y2[j]<=y2[i])&&!(x2[j]==x2[i]&&y2[j]==y2[i]))&&((x2[j]>=x1[i]&&y2[j]>=y1[i])&&!(x2[j]==x1[i]&&y2[j]==y1[i])))||
			(((x2[j]>=x1[i]&&y1[j]<=y2[i])&&!(x2[j]==x1[i]&&y1[j]==y2[i]))&&((x2[j]<=x2[i]&&y1[j]<=y2[i])&&!(x2[j]==x2[i]&&y1[j]==y2[i]))&&((x2[j]>=x1[i]&&y1[j]>=y1[i])&&!(x2[j]==x1[i]&&y1[j]==y1[i]))))
			res[i] += dp(j);
	}
	return res[i];
}
int main()
{
	int w,h;
	cin >> w >> h >> n;
	int i;
	//int *x1 = new int[100000001],*x2 = new int[100000001],*y1 = new int[100000001],*y2 = new int[100000001],*res = new int[100000001];
	for(i=0;i<n;i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	for(i=0;i<n;i++) res[i] = 1;
	//memset(res,0,sizeof(res));
	//res[0] = 1;
	for(i=0;i<n;i++)
	{
		res[i] = dp(i);
	}
	int pp = res[n-1],qq = n;
	for(i=n-1;i>=0;i--) if(res[i] >= pp) {pp = res[i];qq = i+1;}
	//cout << res[0] << res[1];
	cout << pp << ' ' << qq << endl;
	/*
	delete []x1;
	delete []x2;
	delete []y1;
	delete []y2;
	delete []res;
    */
	return 0;
}