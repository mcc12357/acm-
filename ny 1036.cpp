#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,a[1001],sum = 0;
		int i;
		cin >> n;
		for(i=0;i<n;i++) cin >> a[i];		
		sort(a,a+n);
		if(n==1) cout << a[0] << endl;
		else if(n==2) cout << a[1] << endl;
		else if(n==3) cout << a[0] + a[1] + a[2] << endl;
		else 
		{
			

		}

	}
}