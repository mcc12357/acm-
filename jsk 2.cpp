#include<iostream>  
#include<cstring>  
#include<cstdio>  
#include<string>  
#include<algorithm>  
using namespace std;  
#define N 1000010  
  
char s[N * 10], p[N];  
int nextval[N];  
int lens, lenp;  
int w[N];
void getnext()  
{  
    int i = 0, j = -1;  
    nextval[0] = -1;  
    while(i != lenp)  
    {  
        if(j == -1 || s[i] == s[j])  
            nextval[++i] = ++j;  
        else  
            j = nextval[j];  
    }  
}  
  
int KMP()  
{  
    int i = 0, j = 0, count = 0;  
    while(i != lens && j != lenp)  
    {  
        if(s[i] == p[j] || j == -1)  
            ++i, ++j;  
        else  
            j = nextval[j];  
        if(j == lenp)  
        {  
            count++;  
            j = nextval[j];  
        }  
    }  
    return count;  
}  
  
int main()  
{  
	int n,a,b,l,r;
	scanf("%d %d %d %d %d",&n,&a,&b,&l,&r);
	w[0] = b;
	int i;
	for(i=1;i<n;i++) w[i] = (w[i-1] + a) % n;
	for(i=0;i<n;i++)
	{
		if(w[i]>=l && w[i]<=r && w[i]%2==0) s[i] = 'A';
		else if(w[i]>=l && w[i]<=r) s[i] = 'T';
		else if(w[i]%2==0) s[i] = 'G';
		else s[i] = 'C';
	}
    scanf("%s",p);
	lens = n;
	lenp = strlen(p);
	getnext();
    int ans = KMP();  
    printf("%d\n",ans);  
	//printf("%s",s);
    return 0;  
}  
/*lens = strlen(s);  
        lenp = strlen(p);  
          
        ans = KMP();  
        printf("%d\n", ans); 
string s,t;  
	int n,a,b,l,r;
	scanf("%d %d %d %d %d",&n,&a,&b,&l,&r);
	w[0] = b;
	int i;
	for(i=1;i<n;i++) w[i] = (w[i-1] + a) % n;
	for(i=l;i<=r;i++)
	{
		if(w[i]%2==0) s[i] = 'A';
		else s[i] = 'T';
	}
	for(i=0;i<l;i++)
	{
		if(w[i]%2==0) s[i] = 'G';
		else s[i] = 'C';
	}
	for(i=r+1;i<n;i++)
	{
		if(w[i]%2==0) s[i] = 'G';
		else s[i] = 'C';
	}
    cin>>t;
    int ans=find(s,t);  
    printf("%d\n",ans);  
    return 0;  
*/