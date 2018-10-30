#include<iostream>
using namespace std;
#include<stdio.h>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
/*class Solution 
{
public:
	map<string,int> w;
	vector<int> res;
	set<string> show;
    vector<int> findSubstring(string s, vector<string>& words) 
	{
		w.clear();
		int i,j;
		res.clear();
		show.clear();
		if(words.empty()) return res;
		int length = words[0].size();
		for(i=0;i<words.size();i++)
		{
			w[words[i]]++;
		}
		for(i=0;i<words.size();i++)
		{
			if(!(show.find(words[i])==show.end())) continue;
			int index = s.find(words[i],0);
			if(index<0) continue;
			int start = index;
			index += length;
			int k = 1;
			map<string,int> used;
			used.clear();
			used[words[i]]++;
			while(k<words.size()&&index+length<=s.size())
			{
				string sub = s.substr(index,length);
				if(w[sub]<=0 || used[sub]>=w[sub])
				{
					break;
				}
				used[sub]++;
				index += length;
				k++;
			}
			if(k==words.size()) res.push_back(start);
			start = s.find(words[i],start+1);
			while(start>=0 && start<s.size())
			{
				used.clear();
				used[words[i]]++;
				index = start + length;
				k = 1;
				while(k<words.size()&&index+length<=s.size())
				{
					string sub = s.substr(index,length);
					if(w[sub]<=0 || used[sub]>=w[sub])
					{
						break;
					}
					used[sub]++;
					index += length;
					k++;
				}
				if(k==words.size()) res.push_back(start);
				start = s.find(words[i],start+1);
			}
			show.insert(words[i]);
		}
		return res;
    }
};*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty()) return NULL;
		int i;
        int sLen = s.length(), wordsSize = words.size(), perWordLen = words[0].length();
        map<string, int> baseMap;
        for(i = 0; i < wordsSize; i++)
            ++baseMap[words[i]];

        vector<int> ans;
        for(i = 0; i < sLen-wordsSize*perWordLen+1; i++)    {
            map<string, int> comparedMap;
            int j = 0;
            while(j < wordsSize)    {
                string word = s.substr(i+j*perWordLen, perWordLen);
                if(baseMap.find(word) != baseMap.end()) {
                    ++comparedMap[word];
                    if(comparedMap[word] > baseMap[word])
                        break;
                }
                else    break;
                ++j;
            }
            if(j == wordsSize)
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
	Solution a;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	vector<int> res;
	res = a.findSubstring(s,words);
	int i;
	for(i=0;i<res.size();i++) cout<<res[i]<<endl;
}