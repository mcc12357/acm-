#include <iostream>
using namespace std;

//����˲����ڵ���
template<class T>
struct OctreeNode
{
    T data; //�ڵ�����
    T xMin, xMax; //�ڵ����꣬������������������
    T yMin, yMax;
    T zMin, zMax;
    OctreeNode <T> *top_left_front, *top_left_back; //�ýڵ�ĸ��ӽ��
    OctreeNode <T> *top_right_front, *top_right_back;
    OctreeNode <T> *bottom_left_front, *bottom_left_back;
    OctreeNode <T> *bottom_right_front, *bottom_right_back;
    OctreeNode //�ڵ���
    (T nodeValue = T(),
        T xminValue = T(), T xmaxValue = T(),
        T yminValue = T(), T ymaxValue = T(),
        T zminValue = T(), T zmaxValue = T(),
		//ֻ������������д�Ŷ�
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


//�����˲���
template <class T>
void createOctree(OctreeNode<T> * &root, int maxdepth, double xMin, double xMax, double yMin, double yMax, double zMin, double zMax)
{
    cout << "�����У����Ժ򡭡�" << endl;
    maxdepth = maxdepth - 1; //ÿ�ݹ�һ�ξͽ����ݹ����-1
    if (maxdepth >= 0)
    {
        root = new OctreeNode<T>();
        root->data = 9; //Ϊ�ڵ㸳ֵ�����Դ洢�ڵ���Ϣ��������ɼ��ԡ������Ǽ�ʵ�ְ˲������ܣ��򵥸�ֵΪ��
        root->xMin = xMin; //Ϊ�ڵ����긳ֵ
        root->xMax = xMax;
        root->yMin = yMin;
        root->yMax = yMax;
        root->zMin = zMin;
        root->zMax = zMax;
        double xMind = (xMax - xMin) / 2;//����ڵ��ά���ϵİ�߳�
        double yMind = (yMax - yMin) / 2;
        double zMind = (zMax - zMin) / 2;
        //�ݹ鴴������������ÿһ���ڵ��������Ǽ��Žڵ㣩��λ�þ������ӽ������ꡣ
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
//��������˲���
template <class T>
void preOrder(OctreeNode<T> * & p)
{
    if (p)
    {
        cout << i << ".��ǰ�ڵ��ֵΪ��" << p->data << "\n����Ϊ��";
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

//��˲��������
template<class T>
int depth(OctreeNode<T> *& p)
{
    if (p == NULL)
        return -1;
    int h = depth(p->top_left_front);
    return h + 1;
}

//���㵥λ���ȣ�Ϊ���ҵ���׼��
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

//���ҵ�
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
        cout << "�õ㲻�ڳ����У�" << endl;
        return;
    }
    if (x <= p->xMin + txm && x >= p->xMax - txm && y <= p->yMin + tym && 
        y >= p->yMax - tym && z <= p->zMin + tzm && z >= p->zMax - tzm)
    {
        cout << endl << "�ҵ��õ㣡" << "�õ�λ��" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << "�ڵ��ڣ�" << endl;
        cout << "������" << times << "�εݹ飡" << endl;
    }
    else if (x < (p->xMax - xMind) && y < (p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_left_back, x, y, z);
    }
    else if (x < (p->xMax - xMind) && y<(p->yMax - yMind) && z>(p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_left_back, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y < (p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_right_back, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y<(p->yMax - yMind) && z>(p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_right_back, x, y, z);
    }
    else if (x<(p->xMax - xMind) && y>(p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_left_front, x, y, z);
    }
    else if (x<(p->xMax - xMind) && y>(p->yMax - yMind) && z > (p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_left_front, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y > (p->yMax - yMind) && z < (p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->bottom_right_front, x, y, z);
    }
    else if (x > (p->xMax - xMind) && y > (p->yMax - yMind) && z > (p->zMax - zMind))
    {
        cout << "��ǰ�����ڵ����꣺" << endl;
        cout << " xMin: " << p->xMin << " xMax: " << p->xMax;
        cout << " yMin: " << p->yMin << " yMax: " << p->yMax;
        cout << " zMin: " << p->zMin << " zMax: " << p->zMax;
        cout << endl;
        find(p->top_right_front, x, y, z);
    }
}


//main����
int main()
{
    OctreeNode<double> * rootNode = NULL;
    int choiced = 0;
    while (true)
    {
        system("cls");
        cout << "��ѡ�������\n";
        cout << "1.�����˲��� 2.��������˲���\n";
        cout << "3.�鿴����� 4.���ҽڵ�   \n";
        cout << "0.�˳�\n\n";
        cin >> choiced;
        if (choiced == 0)
        {
            return 0;
        }
        else if (choiced == 1)
        {
            system("cls");
            cout << "���������ݹ���ȣ�" << endl;
            cin >> maxdepth;
            cout << "��������������꣬˳�����£�xMin,xMax,yMin,yMax,zMin,zMax" << endl;
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
                cout << "�������";
                return 0;
            }
        }
        else if (choiced == 2)
        {
            system("cls");
            cout << "��������˲��������\n";
            i = 1;
            preOrder(rootNode);
            cout << endl;
            system("pause");
        }
        else if (choiced == 3)
        {
            system("cls");
            int dep = depth(rootNode);
            cout << "�˰˲��������Ϊ" << dep + 1 << endl;
            system("pause");
        }
        else if (choiced == 4)
        {
            system("cls");
            cout << "��������ϣ�����ҵĵ�����꣬˳�����£�x,y,z\n";
            double x, y, z;
            cin >> x >> y >> z;
            times = 0;
            cout << endl << "��ʼ��Ѱ�õ㡭��" << endl;
            find(rootNode, x, y, z);
            system("pause");
        }
        else
        {
            system("cls");
            cout << "\n\n����ѡ��\n";
            system("pause");
        }
    }
}