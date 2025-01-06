#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
vector<int> adj[501];
int vis[501];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	int ans = 0;
	for (auto nxt : adj[1]) {
		ans++;
		q.push(nxt);
		vis[nxt] = 1;
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (auto nxt : adj[cur]) {
			if (!vis[nxt]) {
				ans++;
				vis[nxt] = 1;
			}
		}

	}
	cout << ans;

}
