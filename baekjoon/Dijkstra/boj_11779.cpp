#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
vector<pair<int, int>> adj[20005];
const int INF = 1e9 + 10;
int pre[20005];
int st, en;
int d[20005];
int main() {
	int v, e;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	fill(d, d + v + 1, INF);
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	cin >> st >> en;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;

	pq.push({ d[st],st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (d[cur.second] != cur.first)
			continue;
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) {
				continue;
			}
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second],nxt.second });
			pre[nxt.second] = cur.second;
		}
	}
	cout << d[en] << '\n';
	vector<int> path;
	int cur = en;
	while (cur != st) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());
	cout << path.size() << '\n';
	for (auto x : path)
		cout << x << " ";
}
