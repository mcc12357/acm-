int n;//���и���
int d[_max][_max];//ÿ��������֮��ľ���
int dp[1 << _max][_max];/*dp[s][v],�Ѿ����ʹ��Ľ�㼯��Ϊs����ǰ���Ϊv��*/
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
