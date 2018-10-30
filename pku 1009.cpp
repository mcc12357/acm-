#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<math.h>
#include<map>
int width;
int arr[1005][2];
int total;
int count;
map<int,int> im;
map<int,int>::iterator it;
map<int,int>::iterator tor;
bool inside(int x,int y)
{
	if(x>=1 && x<=width && y>=1 && (y - 1) * width + x <= total) return true;
	return false;
}
int getpix(int x,int y)
{
	int n = (y - 1)* width + x;
	int i;
	for(i=1;i<count;i++)
	{
		if(arr[i][1]>=n) return arr[i][0];
	}
	return -1;
}
int get(int x,int y)
{
	int tmax = -1;
	int tm;
	int t = getpix(x,y);
	int dx,dy;
	for(dx=x-1;dx<=x+1;dx++)
		for(dy=y-1;dy<=y+1;dy++)
		{
			if(inside(dx,dy)) tm = fabs(t - getpix(dx,dy));
			if(tmax<tm) tmax = tm;
		}
	return tmax;
}
int main()
{
	while(~scanf("%d",&width) && width)
	{
		im.clear();
		//printf("%d\n",width);
		total = 0;
		int tm,tn;
		arr[0][1] = 0;
		count = 1;
		while(~scanf("%d %d",&tm,&tn) && (tm || tn))
		{
			arr[count][0] = tm;
			total += tn;
			arr[count][1] = total;
			count++;
		}
		int i;
		for(i=0;i<count;i++)
		{
			int n = arr[i][1] + 1;
			int x,y,dx,dy;
			if(n%width==0)
			{
				x = width;
				y = n / width;
			}
			else
			{
				x = n % width;
				y = n / width + 1;
			}
			//im.insert(make_pair(1,get(0,0)));
			for(dx=x-1;dx<=x+1;dx++)
				for(dy=y-1;dy<=y+1;dy++)
				{
					if(inside(dx,dy))
					{
						im.insert(make_pair(((dy-1)*width+dx),get(dx,dy)));
					}
				}
		}
		printf("%d\n",width);
		it = im.begin();
		while(it!=im.end())
		{
			tor = it;
			tor++;
			for(;tor!=im.end() && tor->second == it->second;tor++);
			if(tor==im.end()) break;
			cout << it->second << " " << (tor->first - it->first) << endl;
			it = tor;
		}
		cout << it->second << " " << (total - it->first + 1) << endl;
		cout << "0 0" << endl;
	}
	cout << "0" << endl;
}