//²¢²é¼¯
//****************************
int par[maxn],rank[maxn];
void init(int n)
{
	int i;
	for(i=0;i<=n;i++) 
	{
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x)
{
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
void merge(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if(a==b) return ;
	if(rank[a]<rank[b])
	{
		par[a] = b;
	}
	else
	{
		par[b] = a;
		if(rank[a]==rank[b]) rank[a]++;
	}
}


//SPFA
//*********************************************************

