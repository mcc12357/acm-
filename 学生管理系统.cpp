#include<iostream>
using namespace std;
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<stack>
struct Student
{
	char name[20];
	int classn;
	char num[20];
	float mathgrade;
	float englishgrade;
};
struct Class
{
	Student student;
	Class *next;
};
struct grade
{
	Student student;
	grade *leftchild;
	grade *rightchild;
};
const int classnum = 191145;
Class *class1,*class2;//ͷ��㲻����Ϣ
grade *math,*english;
int changeflag;
/*void initiategrade(grade **head)
{
	*head = (grade *)malloc(sizeof(grade));
	(*head)->leftchild = NULL;
	(*head)->rightchild = NULL;
}*/
void f()
{
	cin.clear();
	cin.sync();
}
void initiateclass(Class **head)
{
	*head = (Class *)malloc(sizeof(Class));
	(*head)->next = NULL;
}
void classinsert(Class *class3,Student t)
{
	Class *p = class3,*q;
	while(p->next!=NULL)
	{
		p = p->next;
	}
	q = (Class *)malloc(sizeof(Class));
	q->student = t;
	p->next = q;
	q->next = NULL;
	printf("���ӳɹ�!\n");
}
void classdelete(Class *class3,Student tm)
{
	Class *p = class3,*q;
	//q->next = NULL;
	if(class3->next==NULL)
	{
		printf("ɾ��ѧ��������!\n");
		return ;
	}
	while(p->next!=NULL && strcmp(p->next->student.num,tm.num)!=0)
	{
		p = p->next;
	}
	if(p->next==NULL) 
	{
		printf("ɾ��ѧ��������!\n");
		return ;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	
}

void classinsertmath(Class *class1,Student tm)
{
	Class *p = class1->next;
	while(p!=NULL && strcmp(p->student.num,tm.num)) p = p->next;
	if(p==NULL) return;
	p->student.mathgrade = tm.mathgrade;
}
void classinsertenglish(Class *class2,Student tm)
{
	Class *p = class2->next;
	while(p!=NULL && strcmp(p->student.num,tm.num)) p = p->next;
	if(p==NULL) return;
	p->student.englishgrade = tm.englishgrade;
}
void insertmathgrade(grade **root,Student tm)
{
	grade *current,*parent = NULL,*p;
	current = *root;
	while(current!=NULL)
	{
		parent = current;
		if(current->student.mathgrade<tm.mathgrade) current = current->rightchild;
		else current = current->leftchild;
	}
	p = (grade *)malloc(sizeof(grade));
	p->student.classn = tm.classn;
	p->student.mathgrade = tm.mathgrade;
	strcpy(p->student.name,tm.name);
	strcpy(p->student.num,tm.num);
	p->leftchild = NULL;
	p->rightchild = NULL;
	if(parent==NULL)
	{
		*root = p;
	}
	else if(tm.mathgrade<parent->student.mathgrade) parent->leftchild = p;
	else parent->rightchild = p;
	if(tm.classn==classnum)
	{
		classinsertmath(class1,tm);
	}
	else
	{
		classinsertmath(class2,tm);
	}
}
void insertenglishgrade(grade **root,Student tm)
{
	grade *current,*parent = NULL,*p;
	current = *root;
	while(current!=NULL)
	{
		parent = current;
		if(current->student.englishgrade<tm.englishgrade) current = current->rightchild;
		else current = current->leftchild;
	}
	p = (grade *)malloc(sizeof(grade));
	p->student.classn = tm.classn;
	p->student.englishgrade = tm.englishgrade;
	strcpy(p->student.name,tm.name);
	strcpy(p->student.num,tm.num);
	p->leftchild = NULL;
	p->rightchild = NULL;
	if(parent==NULL)
	{
		*root = p;
	}
	else if(tm.englishgrade<parent->student.englishgrade) parent->leftchild = p;
	else parent->rightchild = p;
	if(tm.classn==classnum)
	{
		classinsertenglish(class1,tm);
	}
	else
	{
		classinsertenglish(class2,tm);
	}
}
grade * searchparent(grade *root,grade *p)//pΪ�����㣬rootΪ��ǰ���
{
	if(root->leftchild==p || root->rightchild==p) 
	{
		return root;
	}
	if(root->leftchild!=NULL && searchparent(root->leftchild,p)!=NULL) return searchparent(root->leftchild,p);
	if(root->rightchild!=NULL && searchparent(root->rightchild,p)!=NULL) return searchparent(root->rightchild,p);
	return NULL;
}
grade * searchleft(grade *p)
{
	while(p->leftchild!=NULL) p = p->leftchild;
	return p;
}
void destroytree(grade *root)
{
	if(root->leftchild!=NULL) destroytree(root->leftchild);
	if(root->rightchild!=NULL) destroytree(root->rightchild);
	root->leftchild = NULL;
	root->rightchild = NULL;
	free(root);
}
void recreatemathtree()
{
	if(math->leftchild!=NULL) destroytree(math->leftchild);
	if(math->rightchild!=NULL) destroytree(math->rightchild);
	math->student = class1->next->student;
	math->leftchild = NULL;
	math->rightchild = NULL;
	Class *p = class1->next->next;
	while(p!=NULL) 
	{
		insertmathgrade(&math,p->student);
		p = p->next;
	}
	p = class2;
	while(p!=NULL)
	{
		insertmathgrade(&math,p->student);
		p = p->next;
	}
}
void recreateenglishtree()
{
	if(english->leftchild!=NULL) destroytree(english->leftchild);
	if(english->rightchild!=NULL) destroytree(english->rightchild);
	english->student = class1->next->student;
	english->leftchild = NULL;
	english->rightchild = NULL;
	Class *p = class1->next->next;
	while(p!=NULL) 
	{
		insertenglishgrade(&english,p->student);
		p = p->next;
	}
	p = class2;
	while(p!=NULL)
	{
		insertenglishgrade(&english,p->student);
		p = p->next;
	}
}
void deletemathgrade(grade *p)
{
	grade *parent;
	grade *leftest;
	parent = searchparent(math,p);
	if(parent==NULL)
	{
		recreatemathtree();
		return;
	}
	if(p->leftchild==NULL && p->rightchild==NULL)
	{
		//parent = searchparent(math,p);
		//printf("---%d---",parent->student.mathgrade);
		/*if(parent==NULL)
		{
			p->student = tm;
			return ;
		}*/
		if(parent->leftchild==p)
		{
			parent->leftchild = NULL;
		}
		if(parent->rightchild==p)
		{
			parent->rightchild = NULL;
		}
		free(p);
	}
	else if(p->rightchild==NULL && p->leftchild!=NULL)
	{
		//parent = searchparent(math,p);
		/*if(parent==NULL) 
		{
			free(p);
			return;
		}*/
		if(parent->leftchild==p)
		{
			parent->leftchild = p->leftchild;
		}
		if(parent->rightchild==p)
		{
			parent->rightchild = p->leftchild;
		}
		free(p);
	}
	else if(p->leftchild==NULL && p->rightchild!=NULL)
	{
		//parent = searchparent(math,p);
		/*if(parent==NULL)
		{
			free(p);
			return ;
		}*/
		if(parent->leftchild==p)
		{
			parent->leftchild = p->rightchild;
		}
		if(parent->rightchild==p)
		{
			parent->rightchild = p->rightchild;
		}
		free(p);
	}
	else
	{
		leftest = searchleft(p->rightchild);
		p->student = leftest->student;
		deletemathgrade(p->rightchild);
	}
}
void deleteenglishgrade(grade *p)
{
	grade *parent;
	grade *leftest;
	parent = searchparent(english,p);
	if(parent==NULL)
	{
		recreateenglishtree();
		return;
	}
	if(p->leftchild==NULL && p->rightchild==NULL)
	{
		//parent = searchparent(english,p);
		/*if(parent==NULL)
		{
			free(p);
			return ;
		}*/
		if(parent->leftchild==p)
		{
			parent->leftchild = NULL;
		}
		if(parent->rightchild==p)
		{
			parent->rightchild = NULL;
		}
		free(p);
	}
	else if(p->rightchild==NULL && p->leftchild!=NULL)
	{
		//parent = searchparent(english,p);
		/*if(parent==NULL)
		{
			free(p);
			return;
		}*/
		if(parent->leftchild==p)
		{
			parent->leftchild = p->leftchild;
		}
		if(parent->rightchild==p)
		{
			parent->rightchild = p->leftchild;
		}
		free(p);
	}
	else if(p->leftchild==NULL && p->rightchild!=NULL)
	{
		//parent = searchparent(english,p);
		/*if(parent==NULL)
		{
			free(p);
			return;
		}*/
		if(parent->leftchild==p)
		{
			parent->leftchild = p->rightchild;
		}
		if(parent->rightchild==p)
		{
			parent->rightchild = p->rightchild;
		}
		free(p);
	}
	else
	{
		leftest = searchleft(p->rightchild);
		p->student = leftest->student;
		deleteenglishgrade(p->rightchild);
	}
}
void changemathgrade(grade *root,Student tm)
{
	if(root==NULL) return;
	if(strcmp(tm.num,root->student.num)==0)
	{
		//root->student.mathgrade = tm.mathgrade;
		deletemathgrade(root);
		//insertmathgrade(&math,tm);
		printf("���޸ĸóɼ�!\n");
		changeflag = 0;
		return ;
	}
	if(root->leftchild!=NULL) changemathgrade(root->leftchild,tm);
	if(root->rightchild!=NULL) changemathgrade(root->rightchild,tm);
}
void changeenglishgrade(grade *root,Student tm)
{
	if(root==NULL) return;
	if(strcmp(tm.num,root->student.num)==0)
	{
		//root->student.englishgrade = tm.englishgrade;
		deleteenglishgrade(root);
		//insertenglishgrade(&english,tm);
		printf("���޸ĸóɼ�!\n");
		changeflag = 0;
		return ;
	}
	if(root->leftchild!=NULL) changeenglishgrade(root->leftchild,tm);
	if(root->rightchild!=NULL) changeenglishgrade(root->rightchild,tm);
}

void login()
{
	Student tm;
	printf("������ѧ���༶:\n");
	f();
	//cin>>tm.classn;
	scanf("%d",&tm.classn);
	printf("������ѧ������:\n");
	f();
	//cin>>tm.name;
	scanf(" %s",tm.name);
	printf("������ѧ��ѧ��:\n");
	f();
	//cin>>tm.num;
	scanf(" %s",tm.num);
	tm.mathgrade = 0;
	tm.englishgrade = 0;
	if(tm.classn==classnum)
	{
		classinsert(class1,tm);
	}
	else 
	{
		classinsert(class2,tm);
	}
	printf("ע��ɹ�!\n");
}
void adddelinf()
{
	printf("���������ӻ�ɾ��������Ϊ1��ɾ��Ϊ0\n");
	int n;
	Student tm;
	f();
	//cin>>n;
	scanf("%d",&n);
	if(n)
	{
		printf("����������ѧ���༶:\n");
		f();
		//cin>>tm.classn;
		scanf("%d",&tm.classn);
		printf("����������ѧ������:\n");
		f();
		//cin>>tm.name;
		scanf(" %s",tm.name);
		printf("����������ѧ��ѧ��:\n");
		f();
		//cin>>tm.num;
		scanf(" %s",tm.num);
		tm.mathgrade = 0;
		tm.englishgrade = 0;
		if(tm.classn==classnum)
		{
			classinsert(class1,tm);
		}
		else
		{
			classinsert(class2,tm);
		}
	}
	else
	{
		printf("������ɾ��ѧ���༶:\n");
		f();
		//cin>>tm.classn;
		scanf("%d",&tm.classn);
		printf("������ɾ��ѧ������:\n");
		f();
		//cin>>tm.name;
		scanf(" %s",tm.name);
		printf("������ɾ��ѧ��ѧ��:\n");
		f();
		//cin>>tm.num;
		scanf(" %s",tm.num);
		tm.mathgrade = 0;
		tm.englishgrade = 0;
		if(tm.classn==classnum)
		{
			classdelete(class1,tm);
		}
		else
		{
			classdelete(class2,tm);
		}

	}
}
void inputgrade()
{
	Student tm;
	int k;
	printf("������ѧ�����:\n");
	f();
	scanf("%d",&tm.classn);
	//cin>>tm.classn;
	printf("������ѧ������:\n");
	f();
	//cin>>tm.name;
	scanf(" %s",tm.name);
	printf("������ѧ��ѧ��:\n");
	f();
	//cin>>tm.num;
	scanf(" %s",tm.num);
	printf("������ѧ��,��ѧΪ1,Ӣ��Ϊ0\n");
	f();
	//cin>>k;
	scanf("%d",&k);
	if(k)
	{
		printf("������ɼ�:\n");
		f();
		//cin>>tm.mathgrade;
		scanf("%f",&tm.mathgrade);
		tm.englishgrade = 0;
		insertmathgrade(&math,tm);
	}
	else
	{
		printf("������ɼ�:\n");
		f();
		//cin>>tm.englishgrade;
		scanf("%f",&tm.englishgrade);
		tm.mathgrade = 0;
		insertenglishgrade(&english,tm);
	}

}
void changegrade()
{
	changeflag = 1;
	Student tm;
	printf("������ѧ���İ༶:\n");
	f();
	//cin>>tm.classn;
	scanf("%d",&tm.classn);
	printf("������ѧ��������:\n");
	f();
	//cin>>tm.name;
	scanf(" %s",tm.name);
	printf("������ѧ����ѧ��:\n");
	f();
	//cin>>tm.num;
	scanf(" %s",tm.num);
	printf("������Ҫ�޸ĵ�ѧ�ƣ���ѧΪ1��Ӣ��Ϊ0\n");
	int k;
	f();
	//cin>>k;
	scanf("%d",&k);
	if(k)
	{
		printf("�������޸ĺ�ĳɼ�Ϊ:\n");
		f();
		//cin>>tm.mathgrade;
		scanf("%f",&tm.mathgrade);
		classinsertmath(class1,tm);
		changemathgrade(math,tm);
		
	}
	else 
	{
		printf("�������޸ĺ�ĳɼ�Ϊ:\n");
		f();
		//cin>>tm.englishgrade;
		scanf("%d",&tm.englishgrade);
		classinsertenglish(class2,tm);
		changeenglishgrade(english,tm);
		
	}
	if(changeflag) printf("�޴��ˣ��޸ĳ���!\n");
}
void outputavmathgrade(Class *class3)
{
	int i = 0;
	float sum = 0;
	Class *p = class3->next;
	if(p==NULL) 
	{
		printf("�ð༶����\n");
		return ;
	}
	while(p!=NULL)
	{
		i++;
		sum += p->student.mathgrade;
		p = p->next;
	}
	printf("%.2f\n",sum/i);
}
void outputavenglishgrade(Class *class3)
{
	int i = 0;
	float sum = 0;
	Class *p = class3->next;
	if(p==NULL) 
	{
		printf("�ð༶����\n");
		return ;
	}
	while(p!=NULL)
	{
		i++;
		sum += p->student.englishgrade;
		p = p->next;
	}
	printf("%.2f\n",sum/i);
}
void outputclassavgrade()
{
	int k;
	int kk;
	printf("������Ҫ���ҵĿγ�,��ѧΪ1��Ӣ��Ϊ0:\n");
	f();
	//cin>>k;
	scanf("%d",&k);
	printf("������Ҫ���ҵİ༶:\n");
	f();
	//cin>>kk;
	scanf("%d",&kk);
	if(k)
	{
		if(kk==classnum) outputavmathgrade(class1);
		else outputavmathgrade(class2);
	}
	else
	{
		if(kk==classnum) outputavenglishgrade(class1);
		else outputavenglishgrade(class2);
	}
}
void searchmathnum(int left,int right)
{
	Class *p = class1->next;
	int res = 0;
	while(p!=NULL)
	{
		if(p->student.mathgrade>=left && p->student.mathgrade<=right) res++;
		p = p->next;
	}
	p = class2->next;
	while(p!=NULL)
	{
		if(p->student.mathgrade>=left && p->student.mathgrade<=right) res++;
		p = p->next;
	}
	printf("%d\n",res);
}
void searchenglishnum(int left,int right)
{
	Class *p = class1;
	int res = 0;
	while(p!=NULL)
	{
		if(p->student.englishgrade>=left && p->student.englishgrade<=right) res++;
		p = p->next;
	}
	p = class2;
	while(p!=NULL)
	{
		if(p->student.englishgrade>=left && p->student.englishgrade<=right) res++;
		p = p->next;
	}
	printf("%d\n",res);
}
void outputnum()
{
	printf("������Ҫ���ҵĿγ̣���ѧΪ1��Ӣ��Ϊ0:\n");
	int k;
	f();
	//cin>>k;
	scanf("%d",&k);
	int left,right;
	printf("������Ҫ���ҵķ�����:\n");
	f();
	//cin>>left>>right;
	scanf("%d %d",&left,&right);
	if(k)
	{
		searchmathnum(left,right);
	}
	else
	{
		searchenglishnum(left,right);
	}
}
void outputstdavgrade()
{
	Student tm;
	printf("������ѧ���༶:\n");
	f();
	//cin>>tm.classn;
	scanf("%d",&tm.classn);
	printf("������ѧ������:\n");
	f();
	//cin>>tm.name;
	scanf(" %s",tm.name);
	printf("������ѧ��ѧ��:\n");
	f();
	//cin>>tm.num;
	scanf(" %s",tm.num);
	Class *p;
	if(tm.classn==classnum)
	{
		p = class1->next;
		if(p==NULL)
		{
			printf("�޴�ѧ��!\n");
			return;
		}
		while(p!=NULL && strcmp(p->student.num,tm.num))
		{
			p = p->next;
		}
	}
	else
	{
		p = class2->next;
		if(p==NULL)
		{
			printf("�޴�ѧ��!\n");
			return;
		}
		while(p!=NULL && strcmp(p->student.num,tm.num))
		{
			p->next;
		}
	}
	printf("%.2f\n",(p->student.mathgrade+p->student.englishgrade)/2);
}
void searchstugrade()
{
	Student tm;
	printf("������ѧ���༶:\n");
	f();
	//cin>>tm.classn;
	scanf("%d",&tm.classn);
	printf("������ѧ������:\n");
	f();
	//cin>>tm.name;
	scanf(" %s",tm.name);
	printf("������ѧ��ѧ��:\n");
	f();
	//cin>>tm.num;
	scanf(" %s",tm.num);
	printf("������Ҫ���ҵĿγ�,��ѧΪ1��Ӣ��Ϊ0:\n");
	int k;
	f();
	//cin>>k;
	scanf("%d",&k);
	Class *p;
	if(tm.classn==classnum)
	{
		p = class1->next;
		if(p==NULL)
		{
			printf("��ѧ��������!\n");
			return ;
		}
		while(p!=NULL && strcmp(p->student.num,tm.num)) p = p->next;
		if(p==NULL) 
		{
			printf("��ѧ��������!\n");
			return ;
		}
		if(k) printf("%.2f\n",p->student.mathgrade);
		else printf("%.2f\n",p->student.englishgrade);
	}
	else
	{
		p = class2->next;
		if(p==NULL)
		{
			printf("��ѧ��������!\n");
			return ;
		}
		while(p!=NULL && strcmp(p->student.num,tm.num)) p = p->next;
		if(p==NULL) 
		{
			printf("��ѧ��������!\n");
			return ;
		}
		if(k) printf("%.2f\n",p->student.mathgrade);
		else printf("%.2f\n",p->student.englishgrade);
	}

}
void searchmathinf(grade *p,int left,int right)
{
		if(p!=NULL)
		{
			if(p->student.mathgrade>=left && p->student.mathgrade<=right)
			{
				printf("�༶��%d ������%s ѧ�ţ�%s �ɼ���%.2f\n",p->student.classn,p->student.name,p->student.num,p->student.mathgrade);
			}
			if(p->leftchild!=NULL) searchmathinf(p->leftchild,left,right);
			if(p->rightchild!=NULL) searchmathinf(p->rightchild,left,right);
		}
		else printf("��������ѧ��\n");
}
void searchenglishinf(grade *p,int left,int right)
{
		if(p!=NULL)
		{
			if(p->student.englishgrade>=left && p->student.englishgrade<=right)
			{
				printf("�༶��%d ������%s ѧ�ţ�%s �ɼ���%.2f\n",p->student.classn,p->student.name,p->student.num,p->student.englishgrade);
			}
			if(p->leftchild!=NULL) searchmathinf(p->leftchild,left,right);
			if(p->rightchild!=NULL) searchmathinf(p->rightchild,left,right);
		}
		else printf("��������ѧ��\n");
}
void searchstuname()
{
	int k;
	printf("������Ҫ��ѯ�Ŀγ̣���ѧΪ1��Ӣ��Ϊ0:\n");
	f();
	//cin>>k;
	scanf("%d",&k);
	int left,right;
	printf("������Ҫ��ѯ�ķ�������:\n");
	f();
	//cin>>left>>right;
	scanf("%d %d",&left,&right);
	if(k)
	{
		searchmathinf(math,left,right);
	}
	else
	{
		searchenglishinf(english,left,right);
	}
	
}
void printclassgrade()
{
	printf("������Ҫ��ѯ�İ༶:\n");
	int kk;
	f();
	//cin>>kk;
	scanf("%d",&kk);
	printf("������Ҫ��ѯ�Ŀγ̣���ѧΪ1��Ӣ��Ϊ0\n");
	int k;
	f();
	//cin>>k;
	scanf("%d",&k);
	Class *p;
	if(kk==classnum)
	{
		p = class1->next;
		if(k)
		{
			printf("%d�����ѧ�ɼ�����:\n",kk);
			while(p!=NULL)
			{
				printf("%s %.2f\n",p->student.name,p->student.mathgrade);
				p = p->next;
			}
		}
		else
		{
			printf("%d���Ӣ��ɼ�����:\n",kk);
			while(p!=NULL)
			{
				printf("%s %.2f\n",p->student.name,p->student.englishgrade);
				p = p->next;
			}
		}
	}
	else
	{
		p = class2->next;
		if(k)
		{
			printf("%d�����ѧ�ɼ�����:\n",kk);
			while(p!=NULL)
			{
				printf("%s %.2f\n",p->student.name,p->student.mathgrade);
				p = p->next;
			}
		}
		else
		{
			printf("%d���Ӣ��ɼ�����:\n",kk);
			while(p!=NULL)
			{
				printf("%s %.2f\n",p->student.name,p->student.englishgrade);
				p = p->next;
			}
		}
	}
}
void printstugrade()
{
	printf("������Ҫ���ҵİ༶:\n");
	int kk;
	f();
	//cin>>kk;
	scanf("%d",&kk);
	printf("������Ҫ���ҵ�ѧ������:\n");
	char a[20];
	f();
	//cin>>a;
	scanf(" %s",a);
	Class *p;
	if(kk==classnum)
	{
		p = class1->next;
		while(p!=NULL && strcmp(p->student.name,a)) p = p->next;
		printf("�༶��%d ������%s ��ѧ�ɼ���%.2f Ӣ��ɼ���.2f\n",p->student.classn,p->student.name,p->student.mathgrade,p->student.englishgrade);
	}
	else
	{
		p = class2->next;
		while(p!=NULL && strcmp(p->student.name,a)) p = p->next;
		printf("�༶��%d ������%s ��ѧ�ɼ���%.2f Ӣ��ɼ���.2f\n",p->student.classn,p->student.name,p->student.mathgrade,p->student.englishgrade);
	}
}
int main()
{
	printf("��ӭ����ѧ���ɼ�����ϵͳ!\n");
	initiateclass(&class1);
	initiateclass(&class2);
	//initiategrade(&math);
	//initiategrade(&english);
	int x;
	while(1)
	{
		printf("********************************************************************************\n");
		printf("          1 ѧ��ע��Ǽ�\n");
		printf("          2 ���ӻ�ɾ��ĳ���༶ѧ����Ϣ\n");
		printf("          3 ����ĳѧ���Ŀ��Գɼ�\n");
		printf("          4 �޸�ĳѧ���Ŀ��Գɼ�\n");
		printf("          5 ���ĳ���༶��ѧ��ĳ�ſε�ƽ���ɼ�\n");
		printf("          6 ���ĳ�ſγɼ�����ĳ���������ڵ�ѧ������\n");
		printf("          7 ���ĳһѧ��һѧ�ڸ��Ƶ�ƽ���ɼ�\n");
		printf("          8 ����ĳ��ѧ����ĳ�ſγɼ�\n");
		printf("          9 ����ĳ�ſγ̴���ָ���������ڵ�ѧ������\n");
		printf("          10 ��ӡһ���༶ѧ���ĵ��Ƴɼ�\n");
		printf("          11 ��ӡѧ����ĳ��ѧ�ڵĳɼ�\n\n");
		
		printf("������Ҫ���еĲ���:\n");
		f();
		scanf("%d",&x);
		switch(x)
		{
		case 1: login();break;
		case 2: adddelinf();break;
		case 3: inputgrade();break;
		case 4: changegrade();break;
		case 5: outputclassavgrade();break;
		case 6: outputnum();break;
		case 7: outputstdavgrade();break;
		case 8: searchstugrade();break;
		case 9: searchstuname();break;
		case 10: printclassgrade();break;
		case 11: printstugrade();break;
		case 0: exit(0);break;
		}
	}
	return 0;
}