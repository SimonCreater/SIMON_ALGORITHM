#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include<utility>
#include<queue>
#include<list>
using namespace std;
vector<int> adj[1005];
bool vis[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		num++;
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto nxt : adj[cur]) {
				if (vis[nxt])
					continue;
				q.push(nxt);
				vis[nxt] = 1;
			}

		}
	}
	cout << num;

}
