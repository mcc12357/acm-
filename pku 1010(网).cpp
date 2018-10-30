
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int stamps[100];	//存放邮票的种类（有人说只分配 25 种会不过）
int result[4];		//存放最终结果
int curresult[4];	//存放当前结果
int goal;			//顾客要求的面值
int num;			//邮票种类数
bool tie = false;	//判断是否有tie
int score = 0;		//最优解的分数
int curscore = 0;	//当前解的分数
int cards = 0;		//最优解中有多少张邮票
int curcards = 0;	//当前解中有多少张邮票
int kinds[4];		//记录类型的数组
int kindsnum = 0;	//最优解中有多少种邮票
int curkindsnum = 0;//当前解中有多少种邮票


void DFS(int cur, int index, int curcards)
{
	if((curcards > 3) && (cur != goal))	return;	//失败了，剪枝

	if(cur == goal)		//成功了，开始评分
	{
		curkindsnum = 1;
		for(int i = 1; i < curcards; i++)
		{
			if(kinds[i] != kinds[i-1])
				curkindsnum++;
		}
		curscore = curkindsnum * 100 + (4 - curcards) * 10 + stamps[index];

		if(curscore == score)
		{
			tie = true;
		}
		else if(curscore > score)
		{
			tie = false;
			score = curscore;
			cards = curcards;
			kindsnum = curkindsnum;
			for(int i = 0; i < 4; i++)
				result[i] = curresult[i];
		}
		return;
	}

	for(int i = index; i < num; i++)
	{
		if(cur + stamps[i] > goal)	return;		//剪枝
		curresult[curcards] = stamps[i];
		kinds[curcards] = i;
		DFS(cur + stamps[i], i, curcards + 1);
	}
	return;
}

void Print()
{
	if(!result[0])
	{
		cout << goal << " ---- none" << endl;
		return;
	}

	if(tie)
	{
		cout << goal << " (" << kindsnum << "): tie" << endl;
		return;
	}
	else
	{
		cout << goal << " (" << kindsnum << "): ";
		for(int i = 0; i < cards; i++)
			cout << result[i] << " ";
	}
	cout << endl;
}

int main()
{
	while(true)
	{
		memset(stamps, 0, sizeof(stamps));
		num = 0;
		
		cin >> stamps[0];
		if(!stamps[0])	break;

		while(stamps[num])
		{
			cin >> stamps[++num];
		}
		

		sort(stamps, stamps + num);		//从小到大排序

		while(true)
		{
			memset(result, 0, sizeof(result));
			cin >> goal;
			if(goal == 0)	break;
			if(goal > 4 * stamps[num-1])	//加个判断，不过应该没什么作用
			{
				cout << goal << " ---- none" << endl;
				continue;
			}

			score = 0;
			DFS(0, 0, 0);
			Print();
		}
	}
	return 0;
}