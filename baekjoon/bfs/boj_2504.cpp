#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[101][101];
string board[101];
int dis[101][101];
int main() {
	int n, m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vis[0][0] = 1;
	dis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (vis[nx][ny] || board[nx][ny] == '0')
				continue;
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	cout << dis[n - 1][m - 1];
}
