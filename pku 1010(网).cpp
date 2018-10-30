
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

int stamps[100];	//�����Ʊ�����ࣨ����˵ֻ���� 25 �ֻ᲻����
int result[4];		//������ս��
int curresult[4];	//��ŵ�ǰ���
int goal;			//�˿�Ҫ�����ֵ
int num;			//��Ʊ������
bool tie = false;	//�ж��Ƿ���tie
int score = 0;		//���Ž�ķ���
int curscore = 0;	//��ǰ��ķ���
int cards = 0;		//���Ž����ж�������Ʊ
int curcards = 0;	//��ǰ�����ж�������Ʊ
int kinds[4];		//��¼���͵�����
int kindsnum = 0;	//���Ž����ж�������Ʊ
int curkindsnum = 0;//��ǰ�����ж�������Ʊ


void DFS(int cur, int index, int curcards)
{
	if((curcards > 3) && (cur != goal))	return;	//ʧ���ˣ���֦

	if(cur == goal)		//�ɹ��ˣ���ʼ����
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
		if(cur + stamps[i] > goal)	return;		//��֦
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
		

		sort(stamps, stamps + num);		//��С��������

		while(true)
		{
			memset(result, 0, sizeof(result));
			cin >> goal;
			if(goal == 0)	break;
			if(goal > 4 * stamps[num-1])	//�Ӹ��жϣ�����Ӧ��ûʲô����
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