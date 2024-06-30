#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
#include<utility>
#include<queue>
#include<list>
using namespace std;
vector<int> adj[105];
bool vis[105];
int dist[20005];
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

	}

	queue<int> q;
	q.push(1);
	vis[1] = 1;
	int num = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt])
				continue;
			vis[nxt] = 1;
			q.push(nxt);
			num++;
		}
	}
	cout << num;
	
}
