#include <iostream>
#include <stdio.h>

using namespace std;

int al[10];
void fun(int a,int b)
{
    if(a==0)
    {
        cout<<"kong"<<endl;
        return;
    }
    else
    {
        for(int i=0;i<=b;i++)
        {
            if((a>>i)&1)
            {
                printf("%d ",al[i]);
            }
        }
        cout<<endl;
        fun(a-1,b);
    }
}
int main()
{

    int t;
    while(cin>>t)
    {
        for(int i=0;i<t;i++)
        {
            cin>>al[i];
        }
        //fun((1<<t)-1,t);
		printf("%d\n",(1<<t)-1);
    }
}
