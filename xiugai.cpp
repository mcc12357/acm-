void build(node *root,data dataX[],int dataNum,int height,int *leafnum,int *leafwrongnum)
{	
	root->dataNum = dataNum;//ÿ�α��浱ǰ�ڵ����������
	//����ÿ�ֳ�������ִ���
	calDatanum(&root->num0,&root->num1,&root->num2);
	int numMax = max(num0,max(num1,num2));
	//�������һ���Դﵽ��ֵ��ﵽ���߶ȣ�ֹͣ����������
	if(dataNum<=1 || numMax / dataNum >= stopcondition || height>=maxheight)
	{
		//����Ҷ�ӽڵ�Ĳ���ֵ
		if(num0==numMax) setLeafattr(root,true,0,height);
		else if(num1==numMax) setLeafattr(root,true,1,height);
		else setLeafattr(root,true,2,height);
		return ;
	}
	ʡ�Ա�������ȷǹؼ��Դ���
	//maxGaincal(&maxX,&indexX,tmp,dataNum);
	maxGainratiocal(root,&maxX,&indexX,tmp,dataNum);
	//maxGaincal(&maxY,&indexY,tmp,dataNum);
	maxGainratiocal(root,&maxY,&indexY,tmp,dataNum);
	//maxGaincal(&maxZ,&indexZ,tmp,dataNum);
	maxGainratiocal(root,&maxZ,&indexZ,tmp,dataNum);
	double maxGain = max(maxX,max(maxY,maxZ));
	if(fabs(maxGain-maxX) < eps)//��x���������Ϣ�������
	{
		int leftNum = indexX + 1,rightNum = dataNum - indexX - 1;
		data *leftData = new data[leftNum];
		for(i=0;i<leftNum;i++) leftData[i] = dataX[i];
		data *rightData = new data[rightNum];
		for(i=0;i<rightNum;i++) rightData[i] = dataX[i+leftNum];
		setNoneLeafattr(root,0,dataX[indexX].x,false,height,leftchild,rightchild);
		build(leftchild,leftData,leftNum,height+1,&leftchild->leafnum,&leftchild->leafwrongnum);
		build(rightchild,rightData,rightNum,height+1,&rightchild->leafnum,&rightchild->leafwrongnum);
	}
	else if(fabs(maxGain-maxY) < eps)//��y���������Ϣ�������
	{
		�������������
	}
	else//��z���������Ϣ�������
	{
		�������������
	}
}