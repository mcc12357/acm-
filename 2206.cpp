//´íÎó´úÂë
#include<iostream>
using namespace std;
#include<cstring>
int main()
{
	char a[100];
	while(scanf("%s",a)!=EOF)
	{
		int m;
		m = strlen(a);
		int i;
		int pn = 0,k = 1,s = 1;
		for(i=0;i<m;i++)
		{
			if(a[i]>'9'&&a[i]!='.' || a[i]<'0'&&a[i]!='.') k = 0;
			if(a[i]=='.'&&a[i+1]=='.') k = 0;
			if(a[i] == '.') pn++;
		}
		if(pn!=3 || a[0]=='.' || a[0]=='0'&&a[1]!='.' || a[m-1]=='.') s = 0;
		if(s==1 && k==1)
		{
			int j,p,q=1,x,y,sum1=0,sum2=0,sum3=0,sum4=0;
			for(j=0;j<m;j++)
			{
				if(a[j] == '.') break;
			}

			for(p=j-1;p>=0;p--)
			{
				a[p] = a[p] - '0';
				if(p == j-1) sum1 += a[p];
				else sum1 += a[p] * q;
				q *= 10;
			}
			if(sum1>=0 && sum1<255) 
			{
				if(a[j+1]=='0' && a[j+2]!='.') printf("NO\n");
				else
				{
					for(x=j+1;x<m;x++)
						if(a[x]=='.') break;
						q = 1;
					for(p=x-1;p>j;p--)
						{
							a[p] = a[p] - '0';
							if(p == x-1) sum2 += a[p];
							else sum2 += a[p] * q;
							q *= 10;
						}
					if(sum2>=0 && sum2<255)
					{
						if(a[x+1]=='0' &&a[x+2]!='.') printf("NO\n");
						else
							{
								for(y=x+1;y<m;y++)
									if(a[y]=='.') break;
								q = 1;
								for(p=y-1;p>x;p--)
									{
										a[p] = a[p] - '0';
										if(p == y-1) sum3 += a[p];
										else sum3 += a[p] * q;
										q *= 10;
									}
								if(sum3>=0 && sum3<255)
								{
									if(a[y+1]=='0' && y!=m-2 ) printf("NO\n");
									else
									{
										q = 1;
										for(p=m-1;p>y;p--)
											{
												a[p] = a[p] - '0';
												if(p == m-1) sum4 += a[p];
												else sum4 += a[p] * q;
												q *= 10;
											}
										if(sum4>=0 && sum4<255) printf("YES\n");
											else printf("NO\n");
									}
								}
								else printf("NO\n");

							}

					}
					else printf("NO\n");
				}
			}
			else printf("NO\n");

		}
		else printf("NO\n");
	}
}