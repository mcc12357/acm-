#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
int a[105],b[105];
int d[] = {6,3,1};
void initiate(int n,int b[])
{
	int i;
	for(i=0;i<n;i++) b[i] = a[i];
}
void dirsort(int n,int b[],int &cmp,int &move)
{
	int i,j,temp;
	cmp = 0;
	move = 0;
	for(i=0;i<n-1;i++)
	{
		temp = b[i+1];
		move++;//赋值给temp也算一次移动
		j = i;
		while(j>-1 && temp<b[j])
		{
			b[j+1] = b[j];
			j--;
			cmp++;
			move++;
		}
		cmp++;
		b[j+1] = temp;
		if(j!=i) move++;//赋值给b[j+1]算一次移动
	}
}
void binarysort(int n,int b[],int &cmp,int &move)
{
	int i,j,temp;
	cmp = 0;
	move = 0;
	for(i=1;i<n;i++)
	{
		int l = 0,r = i-1;
		temp = b[i];
		while(l<r)
		{
			int mid = (l+r)/2;
			if(b[i]>b[mid])
			{
				cmp++;
				l = mid+1;
			}
			else 
			{
				cmp++;
				r = mid-1;
			}
			cmp++;
		}
		move = i - l;
		//if(i!=l+1) move += 2;
		for(j=i-1;j>l+1;j--)
		{
			b[j] = b[j-1];
		}
		b[l+1] = temp;
		move++;
	}
}
void shellsort(int n,int b[],int &cmp,int &move)//取希尔增量分别为6,3,1
{
	int i,j,k,m,span;
	int temp;
	cmp = 0;
	move = 0;
	for(m=0;m<3;m++)
	{
		span = d[m];
		for(k=0;k<span;k++)
		{
			for(i=k;i<n-span;i += span)
			{
				temp = b[i+span];
				j = i;
				while(j>-1 && temp<b[j])
				{
					b[j+span] = b[j];
					j = j-span;
					cmp++;
					move++;
				}
				cmp++;
				move += 2;
				b[j+span] = temp;
			}
		}
	}
}
void bubblesort(int n,int b[],int &cmp,int &move)
{
	int i,j,flag = 1;
	int temp;
	cmp = 0;
	move = 0;
	for(i=1;i<n && flag==1;i++)
	{
		flag = 0;
		for(j=0;j<n-i;j++)
		{
			if(b[j]>b[j+1])
			{
				flag = 1;
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
				move += 3;
			}
			cmp++;
		}
	}
}
void qsort(int n,int b[],int &cmp,int &move,int low,int high)
{
	int i = low,j = high;
	int temp = b[low];
	move++;
	while(i<j)
	{
		while(i<j && temp<=b[j]) {j--;cmp++;}
		cmp++;
		if(i<j)
		{
			b[i] = b[j];
			i++;
			move++;
		}
		while(i<j && b[i]<temp) {i++;cmp++;}
		cmp++;
		if(i<j)
		{
			b[j] = b[i];
			j--;
			move++;
		}
	}
	a[i] = temp;
	move++;
	if(low<i) qsort(n,b,cmp,move,low,i-1);
	if(i<high) qsort(n,b,cmp,move,j+1,high);
}
//void mergesort(int n,int b[],int &cmp,int &move)
int main()
{
	int t = 5;
	while(t--)
	{
		int i;
		int n;
		printf("请输入待排序的表长:");
		scanf("%d",&n);
		for(i=0;i<n;i++) a[i] = rand();
		for(i=0;i<n;i++) printf("%d ",a[i]);
		printf("\n");
		int cmp,move;
		initiate(n,b);
		dirsort(n,b,cmp,move);
		printf("直接排序的比较次数为%d,移动次数为%d\n",cmp,move);
		initiate(n,b);
		binarysort(n,b,cmp,move);
		printf("折半插入排序的比较次数为%d,移动次数为%d\n",cmp,move);
		initiate(n,b);
		shellsort(n,b,cmp,move);
		printf("希尔排序的比较次数为%d,移动次数为%d\n",cmp,move);
		initiate(n,b);
		bubblesort(n,b,cmp,move);
		printf("冒泡排序的比较次数为%d,移动次数为%d\n",cmp,move);
		cmp = 0;
		move = 0;
		initiate(n,b);
		qsort(n,b,cmp,move,0,n-1);
		printf("快速排序的比较次数为%d,移动次数为%d\n",cmp,move);
		/*initiate(n,b);
		mergesort(n,b,cmp,move);
		printf("归并排序的比较次数为%d,移动次数为%d\n",cmp,move);*/
	}
}