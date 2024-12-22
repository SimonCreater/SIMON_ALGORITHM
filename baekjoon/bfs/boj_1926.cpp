#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };
int num, mx;
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] || board[i][j] == 0)
				continue;
			q.push({ i,j });
			vis[i][j] = 1;
			int area = 1;
			num++;
			while (!q.empty()) {
				pair<int, int> cur;
				cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					if (vis[nx][ny] || board[nx][ny] == 0)
						continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
					area++;
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << '\\n' << mx;
}

