#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<string>
int f[1010][260];//f[i][mask]��ʾ���е���i��������ǰʹ�ù�����״̬Ϊmask��������г���
int lim = (1<<8) - 1;
int seq[1010];//���ԭ����
int ord[1010];//ord[i]��ʾԭ���еĵ�i��Ԫ�صڼ��γ���
int pos[10][1010];//pos[i][j]��ʾԪ��i����j�ε���ԭ�����е��±�
int cnt[10];//cnt[i]��ʾi���ֵĴ���
int tmp,ans,n;
int max(int x,int y)
{
	if(x<y) return y;
	return x;
}
bool judge(int x)
{
	tmp = 0;
	memset(f,0xef,sizeof(f));//��ʼ��Ϊ������
	f[0][0] = 0;//���е���0�������ҵ�ǰ״̬Ϊ00000000����������г���Ϊ0
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=lim;j++)
		{
			f[i][j] = f[i-1][j];//��ȡ��ǰ��i�����õ��������
			if(j&(1<<seq[i]))//ȡ��ǰ��i������״̬
			{
				int now = ord[i];
				//��ǰ��ȡx��
				if(x>0&&now-x>=0)//x==0������������f[i][j]ֵ,��ǰ��seq[i]���ִ������ڵ�������x�����ſ���ȡseq[i]
				{
					//pos[i][now-x+1]��Ϊ�Ӳ��㵱ǰ���ӵ�ǰ����ǰ�Ѿ�ȡ��x-1����ǰ�������ұߵ�λ�ã�����x-1����ǰ���Ǳ�������ȡ�������У���λ����ǰ�Ĳ���
					//j^(1<<seq[i])��Ϊ������ȡ��ȡ�뵱ǰ״̬һ����jû��ȡ��״̬
					f[i][j] = max(f[i][j],f[pos[seq[i]][now-x+1]-1][j^(1<<seq[i])]+x);
				}
				//��ǰ��ȡ(x+1)��
				if(now-x>=1)
				{
					f[i][j] = max(f[i][j],f[pos[seq[i]][now-x]-1][j^(1<<seq[i])]+x+1);
				}
			}
		}
	}
	if(x==0)
	{
		for(i=0;i<=lim;i++) tmp = max(tmp,f[n][i]);//��ΪxΪ0ʱ��һ��ÿ������Ҫȡ
	}
	else tmp = f[n][lim];//x>=1ʱÿ����������ȡ��x==1ʱҲ��������㣬����ĳ����ȡx+1��ʱ�������һ����û��ȡ�Ͳ�������Ŀ����
	return tmp>0;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&seq[i]);
		seq[i]--;//��1-8��Ӧ��0-7�����ں���λ���㣬�������λ���������seq[i]-1λ
	}
	for(i=1;i<=n;i++)
	{
		ord[i] = ++cnt[seq[i]];
		pos[seq[i]][cnt[seq[i]]] = i;
	}
	int l = 0,r = n / 8;
	while(r>=l)
	{
		int mid = (l + r) >> 1;
		if(judge(mid))
		{
			ans = tmp;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d\n",ans);
}