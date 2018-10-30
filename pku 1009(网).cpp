#include <iostream>  
#include <cstdio>  
#include <string>  
#include <cmath>  
#include <map>  
using namespace std;  
  
int arr[1002][2];  
int width;  
int totalPixs;  
int count;  
  
bool insideImage(int dx,int dy)//dx >= 1, dy >= 1  
{  
    if(dx >= 1 && dy >= 1 && dx <= width   
        && ((dy-1)*width+dx) <= totalPixs  
      )  
        return true;  
    return false;  
}  
  
int getPix(int dx,int dy)//dx >= 1, dy >= 1  
{  
    int x = (dy-1)*width+dx;  
    for(int i = 1; i < count; i++)  
    {  
        if(x <= arr[i][1])  
            return arr[i][0];  
    }  
    return -1;  
}  
  
int getEdv(int dx,int dy)  
{  
    int cpix = getPix(dx,dy);  
    int max = -1,t;  
    for(int i = dx-1; i <= dx+1; i++)  
        for(int j = dy-1; j <= dy+1; j++)  
        {  
            if(insideImage(i,j))  
            {  
                t = fabs(cpix-getPix(i,j));  
                if(t > max)max = t;  
            }  
        }  
    return max;  
}  
  
int main()  
{     
    //freopen("in.txt","r",stdin);  
  
    int px,rle;  
    map<int,int> im;  
    map<int,int>::iterator it;  
    map<int,int>::iterator tor;  
  
    cin>>width;  
    while(width)  
    {  
        cout<<width<<endl;  
  
        //initiation  
        arr[0][1] = 0;  
        totalPixs = 0;  
        count = 1;  
        im.clear();  
          
        while(cin>>px>>rle)  
        {  
            if(px == 0 && rle == 0)  
                break;  
            totalPixs += rle;//  
            arr[count][0] = px;  
            arr[count][1] = totalPixs;  //  
            //cout<<"arr["<<count<<"][0] = "<<arr[count][0]  
            //    <<" arr["<<count<<"][1] = "<<arr[count][1]<<endl;  
            ++count;  
        }                 
  
        {//begin_data_analize  
            for(int i = 0; i < count; i++)  
            {  
                int n = arr[i][1] + 1;//����ֵ�����仯�ĵ�  
      
                //��n��Ӧ�������ʾ�����Ͻ�Ϊ(1,1)��x��������Ϊ�ң�y��������Ϊ��  
                int x,y,dx,dy;  
                if(n % width == 0)  
                    x = width, y = n/width;  
                else  
                    x = n%width, y = n/width + 1;  
  
                //�����x,y������Χ��8�����edvֵ  
                for(dx = x-1; dx <= x+1; dx++)                 
                    for(dy = y-1; dy <= y+1; dy++)  
                    {  
                        if(insideImage(dx,dy))                                                
                            im.insert(make_pair(((dy-1)*width+dx), getEdv(dx,dy)));                       
                    }                 
            }             
      
            it = im.begin();  
            while(it != im.end())//���б������  
            {  
                tor = it;  
                tor++;  
                for(;tor != im.end() && tor->second == it->second;tor++);  
                if(tor == im.end())break;  
                cout<<it->second<<" "<<(tor->first - it->first)<<endl;  
                it = tor;  
            }             
            cout<<it->second<<" "<<(totalPixs - it->first + 1)<<endl;  
            //cout<<endl;  
        }//end_data_analize  
  
        cout<<"0 0"<<endl;  
        cin>>width;  
    }  
    cout<<"0"<<endl;  
    return 1;  
}  