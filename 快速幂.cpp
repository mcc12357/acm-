#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
typedef _int64 ll;
const int mod = 11;
typedef vector<ll> vec;
typedef vector<vec> mat;
/*mat mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B[0].size()));
	int i,j,k;
	for(i=0;i<A.size();i++)
	{
		for(k=0;k<B.size();k++)
		{
			for(j=0;j<B[0].size();j++)
			{
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
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
}*/
struct matrix
{
	ll A[3][3];
}s[25];
matrix operator * (matrix a,matrix b)
{
    matrix ret;
    ret.A[0][0]=(a.A[0][0]*b.A[0][0]%mod+a.A[0][1]*b.A[1][0]%mod+a.A[0][2]*b.A[2][0]%mod)%mod;
    ret.A[0][1]=(a.A[0][0]*b.A[0][1]%mod+a.A[0][1]*b.A[1][1]%mod+a.A[0][2]*b.A[2][1]%mod)%mod;
    ret.A[0][2]=(a.A[0][0]*b.A[0][2]%mod+a.A[0][1]*b.A[1][2]%mod+a.A[0][2]*b.A[2][2]%mod)%mod;
     
    ret.A[1][0]=(a.A[1][0]*b.A[0][0]%mod+a.A[1][1]*b.A[1][0]%mod+a.A[1][2]*b.A[2][0]%mod)%mod;
    ret.A[1][1]=(a.A[1][0]*b.A[0][1]%mod+a.A[1][1]*b.A[1][1]%mod+a.A[1][2]*b.A[2][1]%mod)%mod;
    ret.A[1][2]=(a.A[1][0]*b.A[0][2]%mod+a.A[1][1]*b.A[1][2]%mod+a.A[1][2]*b.A[2][2]%mod)%mod;
     
    ret.A[2][0]=(a.A[2][0]*b.A[0][0]%mod+a.A[2][1]*b.A[1][0]%mod+a.A[2][2]*b.A[2][0]%mod)%mod;
    ret.A[2][1]=(a.A[2][0]*b.A[0][1]%mod+a.A[2][1]*b.A[1][1]%mod+a.A[2][2]*b.A[2][1]%mod)%mod;
    ret.A[2][2]=(a.A[2][0]*b.A[0][2]%mod+a.A[2][1]*b.A[1][2]%mod+a.A[2][2]*b.A[2][2]%mod)%mod;
    return ret;
}
void init()
{
	s[1].A[0][0] = 10;
	s[1].A[0][1] = 1;
	s[1].A[0][2] = 1;
	s[1].A[1][0] = 0;
	s[1].A[1][1] = 1;
	s[1].A[1][2] = 1;
	s[1].A[2][0] = 0;
	s[1].A[2][1] = 0;
	s[1].A[2][2] = 1;
	int i;
	ll k = 10;
	for(i=2;i<=20;i++)
	{
		s[i] = s[i-1];
		s[i].A[0][0] = (k * 10) % mod;
		k *= 10;
	}
}
matrix Ksm(matrix a,ll k)
{
    matrix ret;
    ret.A[0][0]=ret.A[1][1]=ret.A[2][2]=1;
    if (k==0)
        return ret;
    if (k==1)
        return a;
    if (k%2==0)
    {
        ret=Ksm(a,k/2);
        return ret*ret ;
    }else
    {
        ret=Ksm(a,k-1);
        return ret*a;
    }
}
int main()
{
	init();
	ll n;
	while(~scanf("%I64d",&n))
	{
		ll x = n;
		int len = 0;
		ll k = 1;
		while(x)
		{
			len++;
			x /= 10;
			k *= 10;
		}
		k /= 10;
		int i;
		matrix ans;
		ans.A[0][0] = 0;
		ans.A[1][0] = 0;
		ans.A[2][0] = 1;
		ll t = 9;
		matrix tm;
		for(i=1;i<len;i++)
		{
			tm = s[i];
			tm = Ksm(tm,t);
			ans = tm * ans;
			t *= 10;
		}
		tm = s[len];
		tm = Ksm(tm,n-k+1);
		ans = tm*ans;
		printf("%I64d\n",ans.A[0][0]%mod);
	}
}