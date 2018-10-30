struct edge
{
	int from,to,cost;
};
edge es[max_E];
int d[max_E];//d[i]��ʾ�����s��i����̾���
int V,E;//V�Ƕ�������E�Ǳ���
void shortest_path(int s)//������Ϊs�ĵ�Դ���·
{
	int i;
	for(i=0;i<V;i++) d[i] = inf;
	d[s] = 0;
	while(1)
	{
		bool update = false;//ѭ�������ı�־�����ĳ��ɨ�����бߺ�d[i]��û�з����ı䣬˵��d[i]�Ѿ������·������ѭ��
		for(i=0;i<E;i++)
		{
			edge e = es[i];
			if(d[e.from]!=inf && d[e.to]>d[e.from]+e.cost) d[e.to] = d[e.from] + e.cost;
			update = true;
		}
		if(!update) break;
	}
}