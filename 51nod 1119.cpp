#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
typedef _int64 ll;
#define maxn 2000010
ll fact[maxn];
const int p = 1000000007;
int exgcd(int a,int b,int &x,int &y)
{
	int d = a;
	if(b!=0)
	{
		d = exgcd(b,a%b,y,x);
		y -= (a/b) * x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return d;
}
int mod_inverse(int a,int m)
{
	int x,y;
	exgcd(a,m,x,y);
	return (m + x % m) % m;
}
ll mod_fact(int n,int p,int &e)
{
	e = 0;
	if(n==0) return 1;
	ll res = mod_fact(n/p,p,e);
	e += n / p;
	if(n / p % 2 != 0) return res * (p - fact[n % p]) % p;
	return res * fact[n % p] % p;
}
ll mod_comb(int n,int k,int p)
{
	if(n<0 || k<0 || n<k) return 0;
	int e1,e2,e3;
	ll a1 = mod_fact(n,p,e1),a2 = mod_fact(k,p,e2),a3 = mod_fact(n-k,p,e3);
	if(e1 > e2 + e3) return 0;
	return a1 * mod_inverse(a2 * a3 % p,p) % p;
}
void init(int n)
{
	ll i;
	fact[0] = 1;
	fact[1] = 1;
	for(i=2;i<=n;i++) fact[i] = (fact[i-1] * i) % p;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	init(m+n);
	//printf("%d\n",fact[1000]);
	printf("%I64d\n",mod_comb(m+n-2,m-1,p));
}