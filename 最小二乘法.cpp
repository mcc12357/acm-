#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>
typedef _int64 ll;
const double eps = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;
mat gauss_jordan(const mat& A,const mat& b)
{
	int n = A.size();
	mat B(n,vec(n+1));
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) B[i][j] = A[i][j];
	for(i=0;i<n;i++) B[i][n] = b[i][0];
	for(i=0;i<n;i++)
	{
		int pivot = i;
		for(j=i;j<n;j++)
		{
			if(fabs(B[j][i]>fabs(B[pivot][i]))) pivot = j;
		}
		swap(B[i],B[pivot]);
		//if(fabs(B[i][i]<eps)) return mat();
		for(j=i+1;j<=n;j++) B[i][j] /= B[i][i];
		for(j=0;j<n;j++)
		{
			if(i != j)
			{
				int k;
				for(k=i+1;k<=n;k++) B[j][k] -= B[j][i] * B[i][k];
			}
		}
	}
	mat x(n,vec(1));
	for(i=0;i<n;i++) x[i][0] = B[i][n];
	return x;
}
mat mul(mat &A,mat &B)
{
	int i,j,k;
	mat C(A.size(),vec(B[0].size()));
	for(i=0;i<A.size();i++)
	{
		for(k=0;k<B.size();k++)
		{
			for(j=0;j<B[0].size();j++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	return C;
}
void solve(int t)
{
	mat b(8,vec(1));
	int i,j;
	for(i=0;i<8;i++) b[i].clear();
	for(i=0;i<8;i++) 
	{
		double tm;
		scanf("%lf",&tm);
		b[i].push_back(tm);
	}
	//for(i=0;i<8;i++) printf("%.2f\n",b[i][0]);
	mat A(8,vec(t+1));
	for(i=0;i<8;i++) A[i].clear();
	double x[8];
	for(i=0;i<8;i++) scanf("%lf",&x[i]);
	for(i=0;i<8;i++) A[i].push_back(1);
	for(i=1;i<=t;i++)
	{
		for(j=0;j<8;j++)
		{
			A[j].push_back(x[j]);
			x[j] = x[j] * x[j];
		}
	}
	mat B(t+1,vec(8));
	for(i=0;i<8;i++)
		for(j=0;j<=t;j++) B[j][i] = A[i][j];
	mat C(t+1,vec(t+1));
	C = mul(B,A);
	b = mul(B,b);
	mat res(t+1,vec(1));
	res = gauss_jordan(C,b);
	for(i=0;i<=t;i++) printf("%.2f\n",res[i][0]);
}
int main() 
{
	int t;
	scanf("%d",&t);
	solve(t);
}
/*
1
250 260 270 280 290 300 310 320
200 190 176 150 139 125 110 100
*/