#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
char map[200][200];
bool used[200][200];
int n, m;
int a, b, c, d, e;
bool finded,update;
//bool no;
void dfs(int x, int y)
{
	if (map[x][y] == 'X'||(map[x][y] >= 'A'&&map[x][y]<='E')) return;
	else if (map[x][y] >= 'a' && map[x][y] <= 'e'&&!used[x][y])
	{
		used[x][y] = true;
		update = true;
		map[x][y] = '.';
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && x + dx[i] <= n && y + dy[i] >= 0 && y + dy[i] <= m)
				dfs(x + dx[i], y + dy[i]);
		}
	}
	else if ((map[x][y] == '.'||map[x][y] == 'S')&&!used[x][y]) {
		used[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && x + dx[i] <= n && y + dy[i] >= 0 && y + dy[i] <= m&&!used[x+dx[i]][y+dy[i]])
				dfs(x + dx[i], y + dy[i]);
		}
	}
	else if (map[x][y] == 'G') {
		finded = true; return;
	}
	return;
}
void clear(char a)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == a) map[i][j] = '.';
}
int main()
{
	while (scanf("%d%d", &n, &m),n!=0&&m!=0)
	{
		
		finded = false;
		update = true;
		int sx, sy;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 'S') { sx = i, sy = j; break; }
		while (update)
		{
			a = b = c = d = e = 0;
			update = false;
			memset(used, 0, sizeof(used));
			dfs(sx, sy);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (map[i][j] == 'a') a++;
					else if (map[i][j] == 'b')b++;
					else if (map[i][j] == 'c')c++;
					else if (map[i][j] == 'd')d++;
					else if (map[i][j] == 'e')e++;
				}
			if (a == 0) clear('A');
			if (b == 0) clear('B');
			if (c == 0) clear('C');
			if (d == 0) clear('D');
			if (e == 0) clear('E');
		}
		/*for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (map[i][j] >= 'A'&&map[i][j] <= 'E') no = false;
			}*/
		if (finded) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
