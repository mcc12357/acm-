/*
�տ�ʼѭ��˳��㷴�ˣ���ѭ������㣬��ѭ�������䳤�ȡ������Ľ������Ȼres[i][j]��ʾ��iΪ���jΪ�յ��������
�������ƥ�������������ǵ�i��һ��ѭ��������ӵ���0������1����û�и��µĻ����ˣ����Խ����ȫ�����ˡ�ע������dp
����������㣬�յ�2��ѭ�����������++��㲻���и��»��ᡣ����Ӧ��������䳤��ѭ�����ڲ����ѭ����
*/
#include<iostream>
#include<string.h>
using namespace std;
char a[101];
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
bool f(int i,int y)
{
	if(a[i]=='(' && a[y]==')') return true;
	if(a[i]=='[' && a[y]==']') return true;
	return false;
}
int main()
{
	int i,j,k,len;
	int res[101][101];
	memset(res,0,sizeof(res));
	scanf("%s",a);
	len = strlen(a);
	for(i=1;i<=len;i++)//i��ʾ���䳤��
		for(j=0;i+j-1<len;j++)//j��ʾ�������
		{
			int y = j + i - 1;//y��ʾ�յ�����
			if(f(j,y)) res[j][y] = res[j+1][y-1] + 1;
			for(k=j;k<=y;k++)
			{
				res[j][y] = max(res[j][y],res[j][k]+res[k+1][y]);
			}
		}
		cout << res[0][len-1] << endl;
}