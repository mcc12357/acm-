void pushup(int rt)
{
	max[rt] = max(max[rt<<1],max[rt<<1|1]);
	min[rt] = min(min[rt<<1],min[rt<<1|1]);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&min[rt]);
		max[rt] = min[rt];
		sum[rt] = min[rt];
		return ;
	}
	int m = (l + r) >> 1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(int p,int tihuan,int l,int r,int rt)
{
	if(l==r)
	{
		max[rt] = tihuan;
		min[rt] = tihuan;
		sum[rt] = tihuan;
		return ;
	}
	int m = (l + r) >> 1;
	if(p<=m) update(p,tihuan,l,m,rt<<1);
	else update(p,tihuan,m+1,r,rt<<1|1);
	pushup(rt);
}

void update1(int p,int add,int l,int r,inr rt)
{
	if(l==r)
	{
		sum[rt] += add;
		return;
	}
	int m = (l + r) >> 1;
	if(p<=m) update1(p,add,l,m,rt<<1);
	else update1(p,add,m+1,r,rt<<1|1);
	pushup(rt);
}

int querymax(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		return max[rt];
	}
	int m = (l + r) >> 1;
	int ret = -1;
	if(L<=m) ret = max(ret,querymax(L,R,l,m,rt<<1));//���������������һ����
	if(R>m) ret = max(ret,querymax(L,R,m+1,r,rt<<1|1));//�������Һ��������һ����
	return ret;
}

int querymin(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		return min[rt];
	}
	int m = (l + r) >> 1;
	int ret = inf;
	if(L<=m) ret = min(ret,querymin(L,R,l,m,rt<<1));
	if(R>m) ret = min(ret,querymin(L,R,m+1,r,rt<<1|1));
	return ret;
}

int querysum(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if(L<=m) ret += query(L,R,l,m,rt<<1);
	if(R>m) ret += query(L,R,m+1,r,rt<<1|1);
	return ret;
}


//�������
void pushup(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
//**********************************
void pushdown(int rt,int m)//lazy[rt]��ʾ�Ƿ��Ѿ������ӽڵ��ֵ���¹���,���¹���Ϊ0
{
	if(lazy[rt])
	{
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		sum[rt<<1] = (m - (m>>1)) * lazy[rt];
		sum[rt<<1|1] = (m>>1) * lazy[rt];
		lazy[rt] = 0;
	}
}
//**********************************
void build(int l,int r,int rt)
{
	lazy[rt] = 0;
	if(l==r)
	{
		scanf("%d",&sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l && R>=r)//��ǰ������ȫ���������������ڣ����ϱ�ǣ��������¸���
	{
		lazy[rt] = c;
		sum[rt] = c * (r - l + 1);
		return ;
	}
	pushdown(rt,r-l+1);
	int m = (l + r) >> 1;
	if(L<=m) update(L,R,c,l,m,rt<<1);
	if(R>m) update(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
}
 
ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		return sum[rt];
	}
	pushdown(rt,r-l+1);
	int m = (l + r) >> 1;
	ll ret = 0;
	if(L<=m) ret += query(L,R,l,m,rt);
	if(R>m) ret += query(L,R,m+1,r,rt);
	return ret;
}