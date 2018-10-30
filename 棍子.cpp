#include<iostream>
using namespace std;
#include<algorithm>
struct stick
{
	int l;
	int w;
};
bool cmp(struct stick x,struct stick y)
{
	if(x.l==y.l) return (x.w<y.w);
	return (x.l<y.l);
}
int main()
{
	int n;
	struct stick a[5001];
	int b[5001];
	cin>>n;
	while(n--)
	{	
		memset(b,0,sizeof(b));
		//cout<<b[0]<<endl;
		//cout<<b[0]<<b[1]<<c[0]<<c[1];
		int t;
		cin>>t;
		int i,j;
		for(i=0;i<t;i++) cin>>a[i].l>>a[i].w;
		sort(a,a+t,cmp);		
		//for(i=0;i<t;i++) cout<<a[i].l<<a[i].w<<endl;
		int p=0,k;
		for(i=0;i<t;i++)
		{
			if(b[i]==1) continue;
			k=a[i].w;

			for(j=i+1;j<t;j++)
			{	
				if(b[j]==1) continue;
				//cout<<k<<endl;
				if(a[j].w>=k)
				{
					b[i]=1;
					b[j]=1;
					k=a[j].w;
				}

			}		
			p++;
			//cout<<i<<endl;
			//cout<<b[0]<<b[t-1]<<endl;
		}
		cout<<p<<endl;

	}

}