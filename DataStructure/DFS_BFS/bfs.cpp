#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> adj[1001];
int vis[1001];
bool bfs(int x, int y) {
	queue<int> q;
	q.push(x);
	vis[x] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i : adj[cur]) {
			if (!vis[i]) {
				if (i == y) {
					return true;
				}
				vis[i] = 1;
				q.push(i);

			}
		}
	}
	return false;
}
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		if (bfs(a, b)) {
			cout << "True" << '\n';
		}
		else {
			cout << "False" << '\n';
		}
	}
}