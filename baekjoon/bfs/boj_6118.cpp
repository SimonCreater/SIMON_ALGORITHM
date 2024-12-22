#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include<utility>
#include<queue>
#include<list>
using namespace std;
vector<int> adj[20005];
bool vis[20005];
int dist[20005];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		queue<int> q;
		q.push(i);
		vis[i]=1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto nxt : adj[cur]) {
				if (vis[nxt])
					continue;
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
				vis[nxt] = 1;
			}
		}
	}
	int mx = 0;//거리
	int num = 0;//같은 거리 개수
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dist[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (mx == dist[i]) {
			num++;
		}
	}
	int answer = 0;//헛간 번호
	for (int i = 1; i <= n; i++) {
		if (mx == dist[i])
		{
			answer = i;
			break;
		}
	}
	cout << answer << ' ' << mx << ' ' << num;
}
