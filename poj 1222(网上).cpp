#include <iostream>

using namespace std;
int map[7][8],press[7][8];

int text(){
	int i,j;
    for(i=2;i<=5;i++){//����press
        for(j=1;j<=6;j++){
            press[i][j] = (map[i-1][j]+press[i-1][j]+press[i-1][j-1]+press[i-1][j+1]+press[i-2][j])%2;
                     // (map[i-1][j]+press[i-1][j]+press[i-1][j-1]+press[i-1][j+1]+press[i-2][j])%2 ��ʾ����map[i-1][j]��״̬��press[i][j]�϶�������ͬ
        }
    }
    for(i=1;i<=6;i++){
        if((press[5][i-1]+press[5][i]+press[5][i+1]+map[5][i]+press[4][i])%2==1)//���һ�е�״̬�������п��ŵġ����϶�����
            return 0;
    }
    return 1;
}

void get_press(){
    int i;
    for(i=1;i<=6;i++)
        press[1][i] =0;
    while(!text()){
        press[1][1]++;
        i=1;
        while(press[1][i]==2){
            press[1][i]=0;
            i++;
            press[1][i]++;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    int cnt=1;
    while(t--){
		int i,j;
        for(i=1;i<=5;i++)
            for(j=1;j<=6;j++)
                cin>>map[i][j];
        get_press();
        cout<<"PUZZLE #"<<cnt++<<endl;
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++){
                cout<<press[i][j]<<" ";
            }
            cout<<press[i][6]<<endl;
        }
    }
    return 0;
}