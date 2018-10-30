int n;//城市个数
int d[_max][_max];//每两个城市之间的距离
int dp[1 << _max][_max];/*dp[s][v],已经访问过的结点集合为s，当前结点为v。*/
int rec(int s,int v)
{
	if(dp[s][v]>=0) return dp[s][v];//
	if(s==(1<<n)-1 && v==0) return dp[s][v] = 0;
	int res = inf;
	for(u=0;u<n;u++) 
	{
		if(!(s>>u)&1) res = min(res,rec(s|1<<u,u)+d[u][v]);
	}
	return dp[s][v] = res;
}
