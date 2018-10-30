int cost[max_v][max_v];
int d[max_v];
bool used[max_v];
int V;//顶点数
void dijkstra(int s)
{
	fill(d,d+V,inf);
	fill(used,used+V,false);
	d[s] = 0;
	while(true)
	{
		int v = -1;
		for(u=0;u<V;u++)//从未使用过的点集中选择距离源点s最近的点加入使用过的集合
		{
			if(!used[u] && (v==-1 || d[u]<d[v])) v = u;
		}
		if(v==-1) break;//所有点的距离都更新过，则结束循环
		used[v] = true;
		for(u=0;u<V;u++)
		{
			d[u] = min(d[u],d[v]+cost[v][u]);//加入点v后更新其他点通过已使用的点到源点的最短距离
		}
	}
}