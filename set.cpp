#include<iostream>
#include<set>
using namespace std;
typedef struct {
int a,b;
char s;
}newtype;
struct compare //there is no ().
{
bool operator()(const newtype &a, const newtype &b) const
{
return a.s<b.s;
}
};//the ¡°; ¡± is here;
set<newtype,compare>element;
int main()
{
newtype a,b,c,d,t;
a.a=1; a.s='b';
b.a=2; b.s='c';
c.a=4; c.s='d';
d.a=3; d.s='a';
element.insert(a);
element.insert(b);
element.insert(c);
element.insert(d);
set<newtype,compare>::iterator it;
for(it=element.begin(); it!=element.end();it++)
cout<<(*it).a<<" ";
cout<<endl;
for(it=element.begin(); it!=element.end();it++)
cout<<(*it).s<<" ";
}