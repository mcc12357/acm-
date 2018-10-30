struct edge
{
	int from,to,cost;
};
edge es[max_E];
int d[max_E];//d[i]表示从起点s到i的最短距离
int V,E;//V是顶点数，E是边数
void shortest_path(int s)//求解起点为s的单源最短路
{
	int i;
	for(i=0;i<V;i++) d[i] = inf;
	d[s] = 0;
	while(1)
	{
		bool update = false;//循环结束的标志，如果某次扫描所有边后d[i]均没有发生改变，说明d[i]已经是最短路，结束循环
		for(i=0;i<E;i++)
		{
			edge e = es[i];
			if(d[e.from]!=inf && d[e.to]>d[e.from]+e.cost) d[e.to] = d[e.from] + e.cost;
			update = true;
		}
		if(!update) break;
	}
}