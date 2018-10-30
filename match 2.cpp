#include<iostream>
using namespace std;
#include<math.h>
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m,b[51];
		float a[51];
		cin >> m;
		int i,j,k;
		for(i=0;i<m;i++) cin >> a[i] >> b[i];
		int res = 0;
		for(i=0;i<m;i++)
			for(j=0;j<i;j++)
				for(k=0;k<j;k++)
				{
					int temp;
					temp = (int)(a[i]+a[j]+a[k]);
					if(temp%5==0 && fabs(temp-(a[i]+a[j]+a[k]))<0.4) res = max(res,b[i]+b[j]+b[k]);
				}

		for(i=0;i<m;i++)
			for(j=0;j<i;j++)
				{
					int temp;
					temp = (int)(a[i]+a[j]);
					if(temp%5==0 && fabs(temp-(a[i]+a[j]))<0.4) res = max(res,b[i]+b[j]);
				}
		for(i=0;i<m;i++) 
		{
			int temp;
			temp = (int)a[i];
			if(temp%5==0 && fabs(temp-a[i])<0.4) res = max(res,b[i]);
		}
		cout << res << endl;
	}
	return 0;
}