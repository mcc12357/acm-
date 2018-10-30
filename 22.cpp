#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define x first
#define y second
using namespace std;

const int N = 1010;
struct node {
    int x1, x2, y1, y2;
    void in() {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    }
}a[N];
int vis[N], n, res;
vector<int> g[N];


bool in(int x, int y, node p) {
    if (x > p.x1 && x < p.x2 && y > p.y1 && y < p.y2) return 1;
    return 0;
}

bool isok(node p, node q) {
    if (q.y2 > p.y2) swap(p, q);
    if (p.x1 >= q.x2) return 0;
    if (q.x1 >= p.x2) return 0;
    if (p.x1 < q.x2) {
        if (p.y1 < q.y2) return 1;
        return 0;
    }
    if (p.x2 < q.x1) {
        if (p.y1 < q.y2) return 1;
        return 0;
    }
    if (in(q.x1, q.y1, p)) return 1;
    if (in(q.x2, q.y2, p)) return 1;
    if (in(q.x1, q.y2, p)) return 1;
    if (in(q.x2, q.y1, p)) return 1;
    return 0;
}

void dfs(int u) {
	int  i;
    if (vis[u]) return ;
    res++;
    vis[u] = 1;
    for (i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        dfs(v);
    }
}

int main() {
    int w, h, ans = 0, ansk = -1;
    scanf("%d%d%d", &w, &h, &n);
	int i;
    for (i = 0; i < n; i++) {
        a[i].in();
    }
    for (i = n - 1; i >= 0; i--) {
        int flag = 0;
        for (int j = i + 1; j < n; j++) {
            if (isok(a[i], a[j])) {
                g[i].push_back(j);
            }
            if (in(a[i].x1, a[i].y1, a[j])) flag |= 1;
            if (in(a[i].x1, a[i].y2, a[j])) flag |= 2;
            if (in(a[i].x2, a[i].y1, a[j])) flag |= 4;
            if (in(a[i].x2, a[i].y2, a[j])) flag |= 8;

        }
        memset(vis, 0, sizeof(vis));
        res = 0;
        dfs(i);
        if (flag != 15 && ans <= res) ans = res, ansk = i + 1;
    }
    cout << ans << " " << ansk << endl;
}
