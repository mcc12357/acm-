#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
class Solution 
{
public:
    vector<string> res;
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        int i = 0;
        while(i<words.size())
        {
            int j = i;
            string cur = "";
            int charnum = 0;
            int stringnum = 0;
            int totalspacenum = 0;
            while(j<words.size()&&charnum<=maxWidth+1)
            {
                charnum += (words[j].size() + 1);
                stringnum++;
                j++;
            }
            
            if(charnum>maxWidth+1) 
            {
				j--;
                stringnum--;
                charnum -= (words[j].size() + 1);
                if(stringnum==1)
                {
                    cur += words[j-1];
					int k;
                    for(k=1;k<=maxWidth-charnum+1;k++) cur += ' ';
                }
                else
                {
                    if(charnum==maxWidth+1) totalspacenum = stringnum - 1;
                    else totalspacenum = maxWidth - charnum + stringnum;
                    if(totalspacenum%(stringnum-1)==0)
                    {
						int spacenum = totalspacenum / (stringnum - 1);
						int k,t;
                        for(k=i;k<j-1;k++) 
                        {
                            cur += words[k];
							for(t=1;t<=spacenum;t++)
							{
								cur += ' ';
							}
                        }
                        cur += words[j-1];
                    }
                    else
                    {
                        int spacenum = totalspacenum / (stringnum - 1);
                        int more = totalspacenum % (stringnum - 1);
						int k,t;
                        for(t=i;t<j-1;t++)
                        {
                            cur += words[t];
                            for(k=1;k<=spacenum;k++) cur += ' ';
							if(t-i<more) cur += ' ';
                        }
                        cur += words[j-1];
                    }
                }
            }
			else
            {
                if(charnum==maxWidth+1)
                {
                    for(int k=i;k<j-1;k++)
                    {
                        cur += words[k];
                        cur += ' ';
                    }
                    cur += words[j-1];
                }
                else
                {
					int k;
                    for(k=i;k<j;k++)
                    {
                        cur += words[k];
                        cur += ' ';
                    }
                    for(k=1;k<=maxWidth-charnum;k++) cur += ' ';
                }
                
            }
            i = j;
            res.push_back(cur);
        }
        return res;
    }
};
int main()
{
	Solution a;
	int i;
	vector<string> words;
	for(i=1;i<=6;i++) 
	{
		string tmp;
		cin>>tmp;
		words.push_back(tmp);
	}
	vector<string> res;
	res = a.fullJustify(words,16);
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}