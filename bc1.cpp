#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int i,k;
		for(i=0;i<n;i++) cin >> k;
		if(n==1) cout << k << endl;
		else cout << 0 << endl;
	}
}