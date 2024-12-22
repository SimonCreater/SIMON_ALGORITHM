#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int vis[1001][1001];
int board[1001][1001];
int dist[1001][1001];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	cin >> m >> n;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i,j });
				
				vis[i][j] = 1;
			}

		}

	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] || dist[nx][ny] > 0 || board[nx][ny] == -1)
				continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			vis[nx][ny] = 1;
			q.push({ nx,ny });

		}

	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0 && board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			if (mx < dist[i][j])
				mx = dist[i][j];
		}
	}
	cout << mx << '\n';

}
