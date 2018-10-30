#include <iostream>
using namespace std;

//定义八叉树节点类
template<class T>
struct OctreeNode
{
    T data; //节点数据
    T xMin, xMax; //节点坐标，即六面体个顶点的坐标
    T yMin, yMax;
    T zMin, zMax;
    OctreeNode <T> *top_left_front, *top_left_back; //该节点的个子结点
    OctreeNode <T> *top_right_front, *top_right_back;
    OctreeNode <T> *bottom_left_front, *bottom_left_back;
    OctreeNode <T> *bottom_right_front, *bottom_right_back;
    OctreeNode //节点类
    (T nodeValue = T(),
        T xminValue = T(), T xmaxValue = T(),
        T yminValue = T(), T ymaxValue = T(),
        T zminValue = T(), T zmaxValue = T(),
		//只有像上面这样写才对
		/*T nodeValue,
        T xminValue, T xmaxValue,
        T yminValue, T ymaxValue,
        T zminValue, T zmaxValue,*/
        OctreeNode<T>* top_left_front_Node = NULL,
        OctreeNode<T>* top_left_back_Node = NULL,
        OctreeNode<T>* top_right_front_Node = NULL,
        OctreeNode<T>* top_right_back_Node = NULL,
        OctreeNode<T>* bottom_left_front_Node = NULL,
        OctreeNode<T>* bottom_left_back_Node = NULL,
        OctreeNode<T>* bottom_right_front_Node = NULL,
        OctreeNode<T>* bottom_right_back_Node = NULL)
        : data(nodeValue),
        xMin(xminValue), xMax(xmaxValue),
        yMin(yminValue), yMax(ymaxValue),
        zMin(zminValue), zMax(zmaxValue),
        top_left_front(top_left_front_Node),
        top_left_back(top_left_back_Node),
        top_right_front(top_right_front_Node),
        top_right_back(top_right_back_Node),
        bottom_left_front(bottom_left_front_Node),
        bottom_left_back(bottom_left_back_Node),
        bottom_right_front(bottom_right_front_Node),
        bottom_right_back(bottom_right_back_Node) {}
};


//创建八叉树
template <class T>
void createOctree(OctreeNode<T> * &root, int maxdepth, double xMin, double xMax, double yMin, double yMax, double zMin, double zMax)
{
    cout << "处理中，请稍候……" << endl;
    maxdepth = maxdepth - 1; //每递归一次就将最大递归深度-1
    if (maxdepth >= 0)
    {
        root = new OctreeNode<T>();
        root->data = 9; //为节点赋值，可以存储节点信息，如物体可见性。由于是简单实现八叉树功能，简单赋值为。
        root->xMin = xMin; //为节点坐标赋值
        root->xMax = xMax;
        root->yMin = yMin;
        root->yMax = yMax;
        root->zMin = zMin;
        root->zMax = zMax;
        double xMind = (xMax - xMin) / 2;//计算节点个维度上的半边长
        double yMind = (yMax - yMin) / 2;
        double zMind = (zMax - zMin) / 2;
        //递归创建子树，根据每一个节点所处（是几号节点）的位置决定其子结点的坐标。
        createOctree(root->top_left_front, maxdepth, xMin, xMax - xMind, yMax - yMind, yMax, zMax - zMind, zMax);
        createOctree(root->top_left_back, maxdepth, xMin, xMax - xMind, yMin, yMax - yMind, zMax - zMind, zMax);
        createOctree(root->top_right_front, maxdepth, xMax - xMind, xMax, yMax - yMind, yMax, zMax - zMind, zMax);
        createOctree(root->top_right_back, maxdepth, xMax - xMind, xMax, yMin, yMax - yMind, zMax - zMind, zMax);
        createOctree(root->bottom_left_front, maxdepth, xMin, xMax - xMind, yMax - yMind, yMax, zMin, zMax - zMind);
        createOctree(root->bottom_left_back, maxdepth, xMin, xMax - xMind, yMin, yMax - yMind, zMin, zMax - zMind);
        createOctree(root->bottom_right_front, maxdepth, xMax - xMind, xMax, yMax - yMind, yMax, zMin, zMax - zMind);
        createOctree(root->bottom_right_back, maxdepth, xMax - xMind, xMax, yMin, yMax - yMind, zMin, zMax - zMind);
    }
}

int i = 1;
//先序遍历八叉树
template <class T>
void preOrder(OctreeNode<T> * & p)
{
    if (p)
    {
        cout << i << ".当前节点的值为：" << p->data << "\n坐标为：";
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        i += 1;
        cout << endl;
        preOrder(p->top_left_front);
        preOrder(p->top_left_back);
        preOrder(p->top_right_front);
        preOrder(p->top_right_back);
        preOrder(p->bottom_left_front);
        preOrder(p->bottom_left_back);
        preOrder(p->bottom_right_front);
        preOrder(p->bottom_right_back);
        cout << endl;
    }
}

//求八叉树的深度
template<class T>
int depth(OctreeNode<T> *& p)
{
    if (p == NULL)
        return -1;
    int h = depth(p->top_left_front);
    return h + 1;
}

//计算单位长度，为查找点做准备
int cal(int num)
{
    int result = 1;
    if (1 == num)
        result = 1;
    else
    {
        for (int i = 1; i < num; i++)
            result = 2 * result;
    }
    return result;
}

//查找点
int maxdepth = 0;
int times = 0;
static double xMin = 0, xMax = 0, yMin = 0, yMax = 0, zMin = 0, zMax = 0;
int tmaxdepth = 0;
double txm = 1, tym = 1, tzm = 1;

template<class T>
void find(OctreeNode<T> *& p, double x, double y, double z)
{
    double xMind = (p->xMax - p->xMin) / 2;
    double yMind = (p->yMax - p->yMin) / 2;
    double zMind = (p->yMax - p->yMin) / 2;
    times++;
    if (x > xMax || x<xMin || y>yMax || y<yMin || z>zMax || z < zMin)
    {
        cout << "该点不在场景中！" << endl;
        return;
    }
    if (x <= p->xMin + txm && x >= p->xMax - txm && y <= p->yMin + tym && 
        y >= p->yMax - tym && z <= p->zMin + tzm && z >= p->zMax - tzm)
    {
        cout << endl << "找到该点！" << "该点位于" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << "节点内！" << endl;
        cout << "共经过" << times << "次递归！" << endl;
    }
    else if (x < (p->xMax - xMind) && y < (p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_left_back, x, y, z);
    }
    else if (x < (p->xMax - xMind) && y<(p->yMax - yMind) && z>(p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_left_back, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y < (p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_right_back, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y<(p->yMax - yMind) && z>(p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_right_back, x, y, z);
    }
    else if (x<(p->xMax - xMind) && y>(p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_left_front, x, y, z);
    }
    else if (x<(p->xMax - xMind) && y>(p->yMax - yMind) && z > (p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_left_front, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y > (p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_right_front, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y > (p->yMax - yMind) && z > (p->zMax - zMind))
    {
        cout << "当前经过节点坐标：" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_right_front, x, y, z);
    }
}


//main函数
int main()
{
    OctreeNode<double> * rootNode = NULL;
    int choiced = 0;
    while (true)
    {
        system("cls");
        cout << "请选择操作：\n";
        cout << "1.创建八叉树 2.先序遍历八叉树\n";
        cout << "3.查看树深度 4.查找节点   \n";
        cout << "0.退出\n\n";
        cin >> choiced;
        if (choiced == 0)
        {
            return 0;
        }
        else if (choiced == 1)
        {
            system("cls");
            cout << "请输入最大递归深度：" << endl;
            cin >> maxdepth;
            cout << "请输入外包盒坐标，顺序如下：xMin,xMax,yMin,yMax,zMin,zMax" << endl;
            cin >> xMin >> xMax >> yMin >> yMax >> zMin >> zMax;
            if (maxdepth >= 0 || xMax > xMin || yMax > yMin || zMax > zMin || xMin > 0 || yMin > 0 || zMin > 0)
            {
                tmaxdepth = cal(maxdepth);
                txm = (xMax - xMin) / tmaxdepth;
                tym = (yMax - yMin) / tmaxdepth;
                tzm = (zMax - zMin) / tmaxdepth;
                createOctree(rootNode, maxdepth, xMin, xMax, yMin, yMax, zMin, zMax);
            }
            else
            {
                cout << "输入错误！";
                return 0;
            }
        }
        else if (choiced == 2)
        {
            system("cls");
            cout << "先序遍历八叉树结果：\n";
            i = 1;
            preOrder(rootNode);
            cout << endl;
            system("pause");
        }
        else if (choiced == 3)
        {
            system("cls");
            int dep = depth(rootNode);
            cout << "此八叉树的深度为" << dep + 1 << endl;
            system("pause");
        }
        else if (choiced == 4)
        {
            system("cls");
            cout << "请输入您希望查找的点的坐标，顺序如下：x,y,z\n";
            double x, y, z;
            cin >> x >> y >> z;
            times = 0;
            cout << endl << "开始搜寻该点……" << endl;
            find(rootNode, x, y, z);
            system("pause");
        }
        else
        {
            system("cls");
            cout << "\n\n错误选择！\n";
            system("pause");
        }
    }
}