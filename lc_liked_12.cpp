#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
class Solution 
{
public:
    string intToRoman(int num) 
	{
        int digit[3] = {100,10,1};
		char letter1[3] = {'C','X','I'};
		char letter2[3] = {'D','L','V'};
		char letter3[3] = {'M','C','X'};
		string res;
		int i,j;
		int currentNum = num / 1000;
		for(i=1;i<=currentNum;i++) res += 'M';
		num %= 1000;
		for(i=0;i<3;i++)
		{
			currentNum = num / digit[i];
			if(currentNum==0) continue;
			if(currentNum>=1 && currentNum<5)
			{
				if(currentNum==4)
				{
					res += letter1[i];
					res += letter2[i];
				}
				else 
				{
					for(j=1;j<=currentNum;j++)
					{
						res += letter1[i];
					}
				}
			}
			if(currentNum>=5 && currentNum<=9)
			{
				if(currentNum==9)
				{
					res += letter1[i];
					res += letter3[i];
				}
				else
				{
					res += letter2[i];
					for(j=1;j<=currentNum-5;j++)
					{
						res += letter1[i];
					}
				}
			}
			num %= digit[i];
		}
		return res;
    }
};
int main()
{
	Solution a;
	int num = 3;
	string res = a.intToRoman(num);
	cout<<res<<endl;
}