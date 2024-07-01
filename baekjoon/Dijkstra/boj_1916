#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int>> adj[1001];
int INF = 1e9 + 10;
int main() {
	int n, m;
	cin >> n >> m;
	int d[1001];
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	fill(d, d + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int st, de;
	cin >> st >> de;
	d[st] = 0;
	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (d[cur.second] != cur.first)
			continue;
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first)
				continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second],nxt.second });
		}
	}
	cout << d[de];


}
