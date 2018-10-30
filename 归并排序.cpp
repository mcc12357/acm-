/*
*  �鲢�����ǽ�����(����������)�����ϲ���һ���µ���������Ѵ��������з�Ϊ
*  ���ɸ������У�ÿ��������������ģ�Ȼ���ٰ�����������кϲ�Ϊ������������
*  �鲢�����Ƿ����㷨��һ�����͵�Ӧ�ã��������ȶ���һ�������������ù鲢����
*  �Ĺ����У�����ÿ��С������������������õ������������������ô������ͽ���ˡ�
*
*/
#include <stdio.h>

#define max 1000001

long long a[max],b[max];
long long count;
void Merge(long long a[], int start, int mid , int end)  //�鲢����ĺϲ����� 
{
	int i = start,j = mid + 1,k = start;
	while(i <= mid&&j <= end)
	{
		if(a[i] <= a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			count += j - k;
			b[k++] = a[j++];
		}
	}
	while(i <= mid)
	{
		b[k++] = a[i++];
	}
	while(j <= end)
	{
		b[k++] = a[j++];
	}
	for(int i = start; i <= end; i++)
	{
		a[i] = b[i];
	}
}

void MergeSort(long long a[], int start, int end)  //�鲢���� 
{
	if(start < end)
	{
		int mid = (start + end)/2;
		MergeSort(a,start,mid);     // ��ǰ�벿������ 
		MergeSort(a,mid+1,end);     // ����벿������ 
		Merge(a,start,mid,end);     // �ϲ�ǰ���������� 
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		count = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%d",a+i);
		}
		MergeSort(a,0,m-1);
		printf("%lld\n",count);
	}
	return 0;
}