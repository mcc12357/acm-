int cost[max_v][max_v];
int d[max_v];
bool used[max_v];
int V;//������
void dijkstra(int s)
{
	fill(d,d+V,inf);
	fill(used,used+V,false);
	d[s] = 0;
	while(true)
	{
		int v = -1;
		for(u=0;u<V;u++)//��δʹ�ù��ĵ㼯��ѡ�����Դ��s����ĵ����ʹ�ù��ļ���
		{
			if(!used[u] && (v==-1 || d[u]<d[v])) v = u;
		}
		if(v==-1) break;//���е�ľ��붼���¹��������ѭ��
		used[v] = true;
		for(u=0;u<V;u++)
		{
			d[u] = min(d[u],d[v]+cost[v][u]);//�����v�����������ͨ����ʹ�õĵ㵽Դ�����̾���
		}
	}
}