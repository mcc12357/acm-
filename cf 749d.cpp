#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int M = 2e5 + 10;
vector<int>vc[M];
int cp[M] , vis[M] , change[M];
struct TnT {
    int num , val;
}s[M];
bool cmp(TnT a , TnT b) {
    return a.val > b.val;
}
int maxn , maxnnext , temp;
void find() {
    int flag = 0;
    for(int i = 0 ; i < temp ; i++) {
        if(flag == 2) {
            break;
        }
        if(!vis[s[i].num]) {
            if(flag == 0) {
                maxn = s[i].num;
                flag++;
                continue;
            }
            if(flag == 1) {
                maxnnext = s[i].num;
                flag++;
                continue;
            }
        }
    }
}
int binsearch(int pos , int val) {
    int l = 0 , r = vc[pos].size() - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(vc[pos][mid] >= val)
            r = mid - 1;
        else {
            l = mid + 1;
        }
    }
    return r + 1;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        int x , y;
        cin >> x >> y;
        vc[x].push_back(y);
        cp[x] = y;
    }
    temp = 0;
    for(int i = 1 ; i <= M - 10 ; i++) {
        if(cp[i] != 0) {
            s[temp].num = i;
            s[temp++].val = cp[i];
        }
    }
    sort(s , s + temp , cmp);
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        for(int i = 1 ; i <= k ; i++) {
            cin >> change[i];
            vis[change[i]] = 1;
        }
        maxn = 0 , maxnnext = 0;
        find();
        int gg = cp[maxnnext];
        int ans = binsearch(maxn , gg);
        if(maxn == 0) {
            cout << 0 << ' ' << 0 << endl;
        }
        else if(maxnnext == 0) {
            cout << maxn << ' ' << vc[maxn][0] << endl;
        }
        else {
            cout << maxn << ' ' << vc[maxn][ans] << endl;
        }
        for(int i = 1 ; i <= k ; i++) {
            vis[change[i]] = 0;
            change[i] = 0;
        }
    }
    return 0;
}