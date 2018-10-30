#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
#pragma comment(linker, "/STACK:102400000,102400000")
typedef _int64 ll;
//typedef vector<int> vec;
//typedef vector<vec> mat;
struct mat
{
	ll a[32][32];
	int size;
};
int N,m,k;
mat mul (mat A,mat B)
{
	mat C;
	C.size = A.size;
	int i,j,k;
	for(i=0;i<A.size;i++)
	{
		for(j=0;j<A.size;j++)
		{
			C.a[i][j] = 0;
		}
	}
	for(i=0;i<A.size;i++)
	{
		for(k=0;k<B.size;k++)
		{
			for(j=0;j<B.size;j++)
			{
				C.a[i][j] = (C.a[i][j] + (A.a[i][k])*(B.a[k][j])) % m;
			}
		}
	}
	return C;
}

mat pow(mat A,ll n)
{
	mat B;
	B.size = A.size;
	int i,j;
	for(i=0;i<A.size;i++)
	{
		for(j=0;j<A.size;j++)
		{
			if(i==j) B.a[i][j] = 1;
			else B.a[i][j] = 0;
		}
	}
	while(n>0)
	{
		if(n&1) B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}
mat add(mat A,mat B)
{
	int n = A.size;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			A.a[i][j] = ( A.a[i][j]+B.a[i][j]) % m;
		}
	}
	return A;
}
mat PowSumMod(mat A,mat one,int n) // return (a+ a^2 + ... + a^n) Mod m;
{ 
    if( n == 1) return A; 
	//if(n==0) return one;
    if( n % 2 == 0)  
		return mul( PowSumMod(A,one,n>>1),add(pow(A,n>>1),one) ); 
    else  
		return add( PowSumMod(A,one,n-1),pow(A,n)); 
} 
int main()
{
	scanf("%d %d %d",&N,&k,&m);
	int i,j;
	mat A;
	A.size = N;
	mat one;
	one.size = N;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++) 
		{
			scanf("%d",&A.a[i][j]);
			A.a[i][j] = (A.a[i][j]+m) % m;
		}
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i==j) one.a[i][j] = 1;
			else one.a[i][j] = 0;
		}
	}
	A = PowSumMod(A,one,k);
	//printf("%d\n",N);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(j!=N-1) printf("%I64d ",(A.a[i][j]+m)% m);
			else printf("%I64d\n",(A.a[i][j]+m) % m);
		}

}
/*
2 6533 700
7 8
2 5
*/