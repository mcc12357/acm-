#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod = 2147493647;
ll x,a,b;
mat mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B[0].size()));
	int i,j,k;
	for(i=0;i<A.size();i++)
	{
		for(k=0;k<B.size();k++)
		{
			for(j=0;j<B[0].size();j++)
			{
				C[i][j] = (C[i][j] + (A[i][k] % mod) * (B[k][j] % mod) % mod) % mod;
			}
		}
	}
	return C;
}

mat pow(mat A,ll n)
{
	mat B(A.size(),vec(A.size()));
	int i;
	for(i=0;i<A.size();i++)
	{
		B[i][i] = 1;
	}
	while(n>0)
	{
		if(n&1) B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&x,&a,&b);
		if(x==1) 
		{
			printf("%lld\n",a);
			continue;
		}
		else if(x==2)
		{
			printf("%lld\n",b);
			continue;
		}
		else
		{
			mat A(7,vec(7));
			A[0][0] = 1;
			A[0][1] = 2;
			A[0][2] = 1;
			A[0][3] = 4;
			A[0][4] = 6;
			A[0][5] = 4;
			A[0][6] = 1;
			A[1][0] = 1;
			A[1][1] = A[1][2] = A[1][3] = A[1][4] = A[1][5] = A[1][6] = 0;
			A[2][0] = A[2][1] = 0;
			A[2][2] = 1;
			A[2][3] = 4;
			A[2][4] = 6;
			A[2][5] = 4;
			A[2][6] = 1;
			A[3][0] = A[3][1] = A[3][2] = 0;
			A[3][3] = 1;
			A[3][4] = A[3][5] = 3;
			A[3][6] = 1;
			A[4][0] = A[4][1] = A[4][2] = A[4][3] = 0;
			A[4][4] = 1;
			A[4][5] = 2;
			A[4][6] = 1;
			A[5][0] = A[5][1] = A[5][2] = A[5][3] = A[5][4] = 0;
			A[5][5] = A[5][6] = 1;
			A[6][0] = A[6][1] = A[6][2] = A[6][3] = A[6][4] = A[6][5] = 0;
			A[6][6] = 1;
			A = pow(A,x-3);
			mat B(7,vec(1));
			B[0][0] = b + a * 2 + 81;
			B[1][0] = b;
			B[2][0] = 81;
			B[3][0] = 27;
			B[4][0] = 9;
			B[5][0] = 3;
			B[6][0] = 1;
			B = mul(A,B);
			printf("%lld\n",B[0][0]);
		}
	}
}