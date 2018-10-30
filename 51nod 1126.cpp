#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
typedef vector<int> vec;
typedef vector<vec> mat;
typedef _int64 ll;
const int mod = 7;
mat mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B[0].size()));
	int i,j,k;
	for(i=0;i<A.size();i++)
		for(j=0;j<B[0].size();j++)
			for(k=0;k<B.size();k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
	return C;
}
mat pow(mat A,ll n)
{
	mat B(A.size(),vec(A.size()));
	int i;
	for(i=0;i<A.size();i++) B[i][i] = 1;
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
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	if(n==1 || n==2) printf("1\n");
	else
	{
		mat A(2,vec(2));
		A[0][0] = a;
		A[0][1] = b;
		A[1][0] = 1;
		A[1][1] = 0;
		A = pow(A,n-2);
		mat B(2,vec(1));
		B[0][0] = 1;
		B[1][0] = 1;
		B = mul(A,B);
		printf("%d\n",(B[0][0]+mod)%mod);
	}
}