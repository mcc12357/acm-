#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include<iostream>
using namespace std;

typedef struct tag_pcb
{
	char name[8];
	int need;
	int turn;
	struct tag_pcb *next;
}PCB;

int clock = 0;
int jianjie1[10];
int jianjie2[10];
int jianjie3[10];

int temp;

char paixu(int i)
{
	switch (i)
	{
	case 0:return '0'; break;
	case 1:return '1'; break;
	case 2:return '2'; break;
	case 3:return '3'; break;
	case 4:return '4'; break;

	}
}


int main()
{
	PCB *RQ1;
	PCB *RQ2;
	PCB *o,*p,*q;

	printf("��������ؽ��̵�����RQ1\n");

	p = (PCB*)malloc(sizeof(PCB));
	RQ1 = p;

	gets_s(RQ1->name);
	cin >> RQ1->need;
	cin >> RQ1->turn;
	getchar();

	for (int i = 1; i<5; i++)
	{
		q = (PCB*)malloc(sizeof(PCB));
		q->next = NULL;
		gets_s(q->name);

		cin >> q->need;
		cin >> q->turn;
		getchar();
		p->next = q;
		p = q;
	}

	printf("��������ؽ��̵�����RQ2\n");

	p = (PCB*)malloc(sizeof(PCB));
	p->next = NULL;
	RQ2 = p;
	

	gets_s(RQ2->name);

	cin >> RQ2->need;
	cin >> RQ2->turn;
	getchar();

	for (int i = 1; i<5; i++)
	{
		q = (PCB*)malloc(sizeof(PCB));
		q->next = NULL;
		gets_s(q->name);

		cin >> q->need;
		cin >> q->turn;
		getchar();
		p->next = q;
		p = q;
	}
	getchar();
	cout << "***************************************************�˴�ΪRQ1";
	cout << "*********************************************************"<<endl;
	o = RQ1;
	q = RQ1;
	p = q;

	for (int i = 0; i<4; i++)
	{
		o = o->next;
	}
	p = o;
	getchar();
	while (q->next!= NULL)
	{
		if (q->need > 7)
		{
			clock = clock + 7;

			p->next= (PCB*)malloc(sizeof(PCB));
			p->next->next = NULL;

			cout << "���еĽ����";
			puts(q->name);
			//cout << "��ǰʱ��" << clock << endl;

			strcpy_s(p->next->name, q->name );
			p->next->turn = q->turn;
			p->next->need = q->need - 7;
			p = p->next;
			q = q->next;

		}
		else
		{
			clock = clock + 7;
			q->turn = clock + q->turn;
			cout << endl;
			cout << "����������ϣ�";
			cout << "������Ľ�����Ϊ��";
			puts(q->name);
			cout << "�������õ�ʱ�䣺";
			cout << q->turn << endl<<endl;
			q = q->next;

		}
	}

	clock = clock + 7;
	q->turn = clock + q->turn;
	cout << "����������ϣ�";
	cout << "������Ľ�����Ϊ��";
	puts(q->name);
	cout << "�������õ�ʱ�䣺";
	cout << q->turn << endl<<endl;



	//RQ2;
	cout << "***************************************************�˴�ΪRQ2";
	cout << "*********************************************************" << endl;
	q = RQ2;
	for (int i = 0; i < 5; i++)
	{
		jianjie1[i] = q->need;
		jianjie2[i] = q->turn;
		jianjie3[i] = i;
		q = q->next;
	}
	
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = 0; j < 5 - 1 - i; j++)
		{
			if (jianjie1[j]>jianjie1[j+1]) 
			{
				temp = jianjie1[j];
				jianjie1[j] = jianjie1[j + 1];
				jianjie1[j + 1] = temp;

				temp = jianjie2[j];
				jianjie2[j] = jianjie2[j + 1];
				jianjie2[j + 1] = temp;

				temp = jianjie3[j];
				jianjie3[j] = jianjie3[j + 1];
				jianjie3[j + 1] = temp;

			}
		}
		
	}

	q = RQ2;
	for (int i = 0; i < 5; i++)
	{
		q->name[0]= paixu(jianjie3[i]);
		q->need = jianjie1[i];
		q->turn = jianjie2[i];
		q = q->next;
	}
	
	
	q = RQ2;
	clock = 0;
	q = RQ2;
	for (int i = 0; i<5; i++)
	{
		clock = clock + q->need;
		cout << "������ɵĽ���Ϊ��";
		cout << q->name << "  ";
		cout <<clock + q->turn<< endl;
		q = q->next;
	}


	getchar();
	getchar();

}
