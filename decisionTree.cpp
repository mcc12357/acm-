#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<cmath>
int maxheight;
double stopcondition = 0.9;
double eps = 0.001;
struct node
{
	int attr;//0表示x，1表示y，2表示z
	double val;//当前节点的数值
	bool isleaf;//是否是叶子节点
	int sedtype;//0表示冲洪积，1表示湖积，2表示基岩
	int height;//当前树的高度
	node *leftchild;//左子树表示小于等于当前属性值
	node *rightchild;//右子树表示大于当前属性值
};
struct data
{
	double x,y,z;
	int sedtype;
};
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
double max(double a,double b)
{
	if(a>b) return a;
	return b;
}
void init(node *root)
{
	root->isleaf = false;
	root->height = 0;
	root->leftchild = NULL;
	root->rightchild = NULL;
}
bool sortbyX(data a,data b)
{
	if(a.x==b.x)
	{
		if(a.y==b.y)
		{
			return a.z<b.z;
		}
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool sortbyY(data a,data b)
{
	if(a.y==b.y)
	{
		if(a.x==b.x)
		{
			return a.z<b.z;
		}
		return a.x<b.x;
	}
	return a.y<b.y;
}
bool sortbyZ(data a,data b)
{
	if(a.z==b.z)
	{
		if(a.x==b.x)
		{
			return a.y<b.y;
		}
		return a.x<b.x;
	}
	return a.z<b.z;
}
void dataRandom(data a[],int num)
{
	srand((unsigned) time(NULL)); 
	int n = 50000;//随机交换50000次，保证原数据随机
	int i;
	for(i=0;i<n-1;i++)
	{
			int j = rand() % num,k = rand() % num;  //产生0 ~ num-1的随机数j,k
			data tmp;
			tmp = a[j];
			a[j] = a[k];
			a[k] = tmp;
	}
}
void setLeafattr(node *root,bool isleaf,int sedtype,int height)
{
	root->isleaf = isleaf;
	root->sedtype = sedtype;
	root->height = height;
	root->leftchild = NULL;
	root->rightchild = NULL;
}
void setNoneLeafattr(node *root,int attr,double val,bool isleaf,int height,node *leftchild,node *rightchild)
{
	root->attr = attr;
	root->val = val;
	root->isleaf = isleaf;
	root->height = height;
	root->leftchild = leftchild;
	root->rightchild = rightchild;
}
double cal(int start,int end,int a[])
{
	int i;
	int num0 = 0,num1 = 0,num2 = 0;//分别表示entropy属性为0,1,2的结果出现次数
	double sum = 0;
	for(i=start;i<=end;i++)
	{
		if(a[i]==0) num0++;
		if(a[i]==1) num1++;
		if(a[i]==2) num2++;
	}
	if(num0)
	{
		double p0 = num0 * 1.0 / (end - start + 1);
		sum += -p0 * log10(p0) / log10(2);
	}
	if(num1)
	{
		double p1 = num1 * 1.0 / (end - start + 1);
		sum += - p1 * log10(p1) / log10(2);
	}
	if(num2)
	{
		double p2 = num2 * 1.0 / (end - start + 1);
		sum += - p2 * log10(p2) / log10(2);
	}
	return sum;
}
void maxEntropycal(double *maxData,int *index,int a[],int dataNum)
{
	int i = 0,j = 1;
	while(j<dataNum)
	{
		while(a[j]==a[i]) j++;//j指向下一种划分的起点
		double tmp = cal(i,j-1,a) + cal(j,dataNum-1,a);
		if(*maxData<tmp)
		{
			*maxData = tmp;
			*index = j - 1;
		}
		i = j;
		j++;
	}

}
void build(node *root,data dataX[],int dataNum,int height)
{	
	int i;
	int num0 = 0,num1 = 0,num2 = 0;
	//计算每种沉积相出现次数
	for(i=0;i<dataNum;i++)
	{
		if(dataX[i].sedtype==0) num0++;
		if(dataX[i].sedtype==1) num1++;
		if(dataX[i].sedtype==2) num2++;
	}
	int numMax = max(num0,max(num1,num2));
	if(dataNum<=1 || numMax / dataNum >= stopcondition || height>=maxheight)//如果类型一致性达到阀值或达到最大高度，停止决策树生长
	{
		//设置叶子节点的参数值
		if(num0==numMax) setLeafattr(root,true,0,height);
		else if(num1==numMax) setLeafattr(root,true,1,height);
		else setLeafattr(root,true,2,height);
		return ;
	}
	data *dataY = new data[dataNum];
	data *dataZ = new data[dataNum];
	for(i=0;i<dataNum;i++) 
	{
		dataY[i] = dataX[i];
		dataZ[i] = dataX[i];
	}
	sort(dataX,dataX+dataNum,sortbyX);
	sort(dataY,dataY+dataNum,sortbyY);
	sort(dataZ,dataZ+dataNum,sortbyZ);
	int *tmp = new int[dataNum];
	double maxX = -1,maxY = -1,maxZ = -1;
	int indexX = 0,indexY = 0,indexZ = 0;
	node *leftchild,*rightchild;
	leftchild = (node*)malloc(sizeof(node));
	rightchild = (node*)malloc(sizeof(node));
	init(leftchild);
	init(rightchild);
	for(i=0;i<dataNum;i++)
	{
		tmp[i] = dataX[i].sedtype;
	}
	maxEntropycal(&maxX,&indexX,tmp,dataNum);
	for(i=0;i<dataNum;i++)
	{
		tmp[i] = dataY[i].sedtype;
	}
	maxEntropycal(&maxY,&indexY,tmp,dataNum);
	for(i=0;i<dataNum;i++)
	{
		tmp[i] = dataZ[i].sedtype;
	}
	maxEntropycal(&maxZ,&indexZ,tmp,dataNum);
	double maxEntropy = max(maxX,max(maxY,maxZ));
	if(fabs(maxEntropy-maxX) < eps)
	{
		int leftNum = indexX + 1,rightNum = dataNum - indexX - 1;
		data *leftData = new data[leftNum];
		for(i=0;i<leftNum;i++) leftData[i] = dataX[i];
		data *rightData = new data[rightNum];
		for(i=0;i<rightNum;i++) rightData[i] = dataX[i+leftNum];
		setNoneLeafattr(root,0,dataX[indexX].x,false,height,leftchild,rightchild);
		build(leftchild,leftData,leftNum,height+1);
		build(rightchild,rightData,rightNum,height+1);
	}
	else if(fabs(maxEntropy-maxY) < eps)
	{
		int leftNum = indexY + 1,rightNum = dataNum - indexY - 1;
		data *leftData = new data[leftNum];
		for(i=0;i<leftNum;i++) leftData[i] = dataY[i];
		data *rightData = new data[rightNum];
		for(i=0;i<rightNum;i++) rightData[i] = dataY[i+leftNum];
		setNoneLeafattr(root,1,dataY[indexY].y,false,height,leftchild,rightchild);
		build(leftchild,leftData,leftNum,height+1);
		build(rightchild,rightData,rightNum,height+1);
	}
	else
	{
		int leftNum = indexZ + 1,rightNum = dataNum - indexZ - 1;
		data *leftData = new data[leftNum];
		for(i=0;i<leftNum;i++) leftData[i] = dataZ[i];
		data *rightData = new data[rightNum];
		for(i=0;i<rightNum;i++) rightData[i] = dataZ[i+leftNum];
		setNoneLeafattr(root,2,dataZ[indexZ].z,false,height,leftchild,rightchild);
		build(leftchild,leftData,leftNum,height+1);
		build(rightchild,rightData,rightNum,height+1);
	}

}
void showDecisionTree(node *root)
{
	if(root && root->isleaf==true)
	{
		printf("sedtype:%d height:%d\n",root->sedtype,root->height);
		return ;
	}
	printf("attr:%d val:%lf height:%d\n",root->attr,root->val,root->height);
	if(root->leftchild) showDecisionTree(root->leftchild);
	if(root->rightchild) showDecisionTree(root->rightchild);
}
int main()
{
	while(~scanf("%d",&maxheight))
	{
		data origin[2000];
		FILE * fp=fopen("C:\\origin.txt","r");   
		//读文件 
		int num=0;
		while(fscanf(fp,"%d %lf %lf %lf",&origin[num].sedtype,&origin[num].x,&origin[num].y,&origin[num].z)!=EOF)
		{
			 //printf("%d %lf %lf %lf\n",origin[num].sedtype,origin[num].x,origin[num].y,origin[num].z);//输出到显示器屏幕 
			 num++;
		}
		fclose(fp);
		//printf("%d\n",num);//num=575
		//dataRandom(origin,num);
		int trainnum = 450;
		int predictnum = num - trainnum;
		data *trainData = new data[trainnum];
		data *predictData = new data[predictnum];
		int i = 0;
		//FILE *fpwtrain = fopen("C:\\trainC.txt","w");
		//FILE *fpwpredict = fopen("C:\\predictC.txt","w");
		for(i=0;i<trainnum;i++)
		{
			trainData[i] = origin[i];
			//fprintf(fpwtrain,"%d %lf %lf %lf\n",trainData[i].sedtype,trainData[i].x,trainData[i].y,trainData[i].z);
		}
		for(i=trainnum;i<num;i++)
		{
			predictData[i-trainnum] = origin[i];
			//fprintf(fpwpredict,"%d %lf %lf %lf\n",origin[i].sedtype,origin[i].x,origin[i].y,origin[i].z);
		}
		//fclose(fpwtrain);
		//fclose(fpwpredict);

		//读入训练集数据
		i = 0;
		FILE *fprtrain = fopen("C:\\trainC.txt","r");
		while(fscanf(fprtrain,"%d %lf %lf %lf",&trainData[i].sedtype,&trainData[i].x,&trainData[i].y,&trainData[i].z)!=EOF)
		{
			//printf("%d %lf %lf %lf\n",trainData[i].sedtype,trainData[i].x,trainData[i].y,trainData[i].z);//输出到显示器屏幕 
			i++;
		}
		fclose(fprtrain);

		//读入测试集数据
		i = 0;
		FILE *fprpredict = fopen("C:\\predictC.txt","r");
		while(fscanf(fprpredict,"%d %lf %lf %lf",&predictData[i].sedtype,&predictData[i].x,&predictData[i].y,&predictData[i].z)!=EOF)
		{
			//printf("%d %lf %lf %lf\n",predictData[i].sedtype,predictData[i].x,predictData[i].y,predictData[i].z);//输出到显示器屏幕 
			i++;
		}

		node *root;
		root = (node*)malloc(sizeof(node));
		init(root);
		build(root,trainData,trainnum,0);
		//pepPrune(root,)
		//showDecisionTree(root);

		//预测准确度模块
		int rightpredict = 0;//准确预测组数
		for(i=0;i<predictnum;i++)
		{
			node *tmp = root;
			while(true)
			{
				if(tmp->isleaf==true)
				{
					if(tmp->sedtype==predictData[i].sedtype) rightpredict++;
					break;
				}
				if(tmp->attr==0)
				{
					if(predictData[i].x<=tmp->val) tmp = tmp->leftchild;
					else tmp = tmp->rightchild;
				}
				if(tmp->attr==1)
				{
					if(predictData[i].y<=tmp->val) tmp = tmp->leftchild;
					else tmp = tmp->rightchild;
				}
				if(tmp->attr==2)
				{
					if(predictData[i].z<=tmp->val) tmp = tmp->leftchild;
					else tmp = tmp->rightchild;
				}
			}
		}
		printf("%d\n",rightpredict);
	}
}
