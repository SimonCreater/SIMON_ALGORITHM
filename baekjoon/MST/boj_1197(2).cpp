#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int v, e;
vector<pair<int, int>> adj[10005];

bool chk[10005];
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int cost, a, b;
		cin >>a>>b>>cost;
		adj[a].push_back({ cost,b });
		adj[b].push_back({ cost,a });
		
	}
	priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	chk[1] = 1;

	for (auto nxt : adj[1]) {
		pq.push({ nxt.first,1,nxt.second });
	}
	int ans = 0;
	int cnt = 0;
	while (cnt < v - 1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b])
			continue;
		ans += cost;
		cnt++;
		chk[b] = 1;
		for (auto nxt : adj[b]) {
			if (!chk[nxt.second])
				pq.push({ nxt.first,b,nxt.second });
		}
	}
	cout << ans;
}