//����������ʱ����ÿһλ�ﲻһ��ֻ����һλ�����Ա����λ����a[n][max-1]��ʾΪnʱ�Ľ����a[n][1]���Ա���4λ������Դ�����
#include<iostream>
using namespace std;
#include<string.h>
const int MAX = 100;
const int BASE = 10000;
void multiply(int a[],int max,int b)//�����˷�
{
	int i,array = 0;
	for(i=max-1;i>=0;i--)
	{
		array += b * a[i];//b*a[i]�����4λ��������BASE��������1e5,����ò�����ǰλ��ȷ���
		a[i] = array % BASE;
		array /= BASE;
	}
}
void divide(int a[],int max,int b)//��������
{
	int i,div = 0;
	for(i=0;i<max;i++)
	{
		div = div * BASE + a[i];
		a[i] = div / b;
		div %= b;
	}
}
int main()
{
	int a[101][MAX],i,j,n;
	memset(a[1],0,MAX*sizeof(int));
	for(i=2,a[1][MAX-1]=1;i<101;i++)
	{
		memcpy(a[i],a[i-1],MAX*sizeof(int));
		multiply(a[i],MAX,4 * i - 2);
		divide(a[i],MAX,i + 1);
	}
	while(cin>>n)
	{
		for(i=0;i<MAX && a[n][i]==0;i++);//ȥ������ǰΪ0������
		cout << a[n][i++];//�����һ����0��
		for(;i<MAX;i++)
			printf("%04d",a[n][i]);
		cout << endl;
	}
	return 0;
}