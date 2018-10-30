void build(node *root,data dataX[],int dataNum,int height,int *leafnum,int *leafwrongnum)
{	
	root->dataNum = dataNum;//每次保存当前节点的总样本数
	//计算每种沉积相出现次数
	calDatanum(&root->num0,&root->num1,&root->num2);
	int numMax = max(num0,max(num1,num2));
	//如果类型一致性达到阀值或达到最大高度，停止决策树生长
	if(dataNum<=1 || numMax / dataNum >= stopcondition || height>=maxheight)
	{
		//设置叶子节点的参数值
		if(num0==numMax) setLeafattr(root,true,0,height);
		else if(num1==numMax) setLeafattr(root,true,1,height);
		else setLeafattr(root,true,2,height);
		return ;
	}
	省略变量定义等非关键性代码
	//maxGaincal(&maxX,&indexX,tmp,dataNum);
	maxGainratiocal(root,&maxX,&indexX,tmp,dataNum);
	//maxGaincal(&maxY,&indexY,tmp,dataNum);
	maxGainratiocal(root,&maxY,&indexY,tmp,dataNum);
	//maxGaincal(&maxZ,&indexZ,tmp,dataNum);
	maxGainratiocal(root,&maxZ,&indexZ,tmp,dataNum);
	double maxGain = max(maxX,max(maxY,maxZ));
	if(fabs(maxGain-maxX) < eps)//按x分类求得信息增益最大
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
	else if(fabs(maxGain-maxY) < eps)//按y分类求得信息增益最大
	{
		和上面代码类似
	}
	else//按z分类求得信息增益最大
	{
		和上面代码类似
	}
}