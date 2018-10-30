#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
#include<algorithm>
typedef vector<double> vec;
typedef vector<vec> mat;
//typedef _int64 ll;
int mine[15];
mat mul(mat &A,mat &B)//calculate A*B
{
	mat C(A.size(),vec(B[0].size()));
	int i,j,k;
	for(i=0;i<A.size();i++)
	{
		for(k=0;k<B.size();k++)
		{
			for(j=0;j<B[0].size();j++)
			{
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
			}
		}
	}
	return C;
}
mat pow(mat A,int n)
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
	int t;
	double p;
	while(~scanf("%d %lf",&t,&p))
	{
		double q = 1 - p;
		int i;
		for(i=1;i<=t;i++) scanf("%d",&mine[i]);
		sort(mine,mine+t+1);
		mine[0] = 0;
		double res = 1;
		for(i=1;i<=t;i++)
		{
			int len = mine[i] - mine[i-1];
			if(len<=1) {res = 0.0000000;break;}
			else if(len==2) res *= q;
			else
			{
				mat A(2,vec(1));
				A[0][0] = p;
				A[1][0] = 1;
				mat B(2,vec(2));
				B[0][0] = p;
				B[0][1] = q;
				B[1][0] = 1;
				B[1][1] = 0;
				B = pow(B,len-3);
				//printf("%lf %lf %lf %lf\n",B[0][0],B[0][1],B[1][0],B[1][1]);
				A = mul(B,A);
				//printf("%lf %lf\n",A[0][0],A[1][0]);
				res *= A[0][0] * q;
			}
		}
		printf("%.7f\n",res);
	}
}