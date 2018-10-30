#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<cmath>
#define maxn 500010
int n,p,q;
struct Piece
{
	int x,y;
	char ty;
	bool exist;
}piece[8];
int a[maxn],b[maxn];
char c[maxn][10];
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&p,&q);
	int i;
	for(i=0;i<n;i++) scanf("%s %d %d",c[i],&a[i],&b[i]);
	for(i=0;i<=7;i++) piece[i].exist = false;
	for(i=0;i<n;i++)
	{
		if(a[i]==p && b[i]<q && (!piece[0].exist || (piece[0].exist && b[i]>piece[0].y)))
		{
			piece[0].exist = true;
			piece[0].x = a[i];
			piece[0].y = b[i];
			piece[0].ty = c[i][0];
		}
		if(a[i]==p && b[i]>q && (!piece[1].exist || (piece[1].exist && b[i]<piece[1].y)))
		{
			piece[1].exist = true;
			piece[1].x = a[i];
			piece[1].y = b[i];
			piece[1].ty = c[i][0];
		}
		if(b[i]==q && a[i]<p && (!piece[2].exist || (piece[2].exist && a[i]>piece[2].x)))
		{
			piece[2].exist = true;
			piece[2].x = a[i];
			piece[2].y = b[i];
			piece[2].ty = c[i][0];
		}
		if(b[i]==q && a[i]>p && (!piece[3].exist || (piece[3].exist && a[i]<piece[3].x)))
		{
			piece[3].exist = true;
			piece[3].x = a[i];
			piece[3].y = b[i];
			piece[3].ty = c[i][0];
		}
		if(a[i]<p && b[i]>q && fabs(p-a[i])==fabs(q-b[i]) && (!piece[4].exist || (piece[4].exist && a[i]>piece[4].x)))
		{
			piece[4].exist = true;
			piece[4].x = a[i];
			piece[4].y = b[i];
			piece[4].ty = c[i][0];
		}
		if(a[i]<p && b[i]<q && fabs(p-a[i])==fabs(q-b[i]) && (!piece[5].exist || (piece[5].exist && a[i]<piece[4].x)))
		{
			piece[5].exist = true;
			piece[5].x = a[i];
			piece[5].y = b[i];
			piece[5].ty = c[i][0];
		}
		if(a[i]>p && b[i]>q && fabs(p-a[i])==fabs(q-b[i]) && (!piece[6].exist || (piece[6].exist && a[i]>piece[6].x)))
		{
			piece[6].exist = true;
			piece[6].x = a[i];
			piece[6].y = b[i];
			piece[6].ty = c[i][0];
		}
		if(a[i]>p && b[i]<q && fabs(p-a[i])==fabs(q-b[i]) && (!piece[7].exist || (piece[7].exist && a[i]<piece[7].x)))
		{
			piece[7].exist = true;
			piece[7].x = a[i];
			piece[7].y = b[i];
			piece[7].ty = c[i][0];
		}
	}
	bool flag = false;
	for(i=0;i<8;i++)
	{
		if(i<4)
		{
			if(piece[i].ty=='R' || piece[i].ty=='Q') {flag = true;break;}
		}
		else
		{
			if(piece[i].ty=='B' || piece[i].ty=='Q') {flag = true;break;}
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
 
}