#include<iostream>
using namespace std;
#include<stdio.h>
#define MAX 10
struct matrix
{
	int m,n;
	int a[MAX][MAX];
};
void input_matrix(matrix *x)
{
	int i,j;
	for(i=0;i<x->m;i++)
		for(j=0;j<x->n;j++) scanf("%d",&x->a[i][j]);
}
void output_matrix(matrix x)
{
	int i,j;
	for(i=0;i<x.m;i++)
	{
		for(j=0;j<x.n;j++)
		{
			printf("%d ",x.a[i][j]);
		}
		printf("\n");
	}
}
void exchange_row(int *a,int *b,int n)//交换两行
{
	int i,t;
	for(i=0;i<n;i++)
	{
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}
void mul_row(int *a,int k,int n)//将某一行乘以k
{
	int i;
	for(i=0;i<n;i++) a[i] *= k;
}
void add_row(int *a1,int *a2,int k,int n)//将a2的k倍加到a1行上
{
	int i;
	for(i=0;i<n;i++)
	{
		a1[i] += a2[i] * k;
	}
}
int rank_matrix(matrix dat,matrix *res)//返回秩，第二个参数为变换得到的阶梯阵
{
	int m,n,i,t;
	int ri,ci;
	int f_z;
	m = dat.m;
	n = dat.n;
	for(ri=ci=0;ci<n;ci++)
	{
		f_z = 1;
		for(i=ri;i<m;i++)
		{
			if(dat.a[i][ci]!=0)
			{
				if(i!=ri)
				{
					if(f_z) exchange_row(&(dat.a[ri][ci]),&(dat.a[i][ci]),n-ci);
					else
					{
						t = dat.a[i][ci];
						mul_row(&(dat.a[i][ci]),dat.a[ri][ci],n-ci);
						add_row(&(dat.a[i][ci]),&dat.a[ri][ci],-t,n-ci);
					}
				}
				f_z = 0;
			}
		}
		if(!f_z) ri++;	
	}
	*res = dat;
	return ri;
}
int main()
{
	matrix x,y;
	scanf("%d %d",&x.m,&x.n);
	input_matrix(&x);
	output_matrix(x);
	int r = rank_matrix(x,&y);
	printf("%d\n",r);
	output_matrix(y);
}