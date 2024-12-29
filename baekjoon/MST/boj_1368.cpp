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
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cost;
		cin >> cost;
		adj[i].push_back({ cost, 0 });
		adj[0].push_back({ cost, i });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i == j)
				continue;
			adj[i].push_back({ cost,j });
		}
	}
	int ans = 0;
	int cnt = 0;
	for (auto nxt : adj[1]) {
		pq.push({ nxt.first,1,nxt.second });
	}
	chk[1] = 1;

	while (cnt < n) {
		int cost, a, b;
		tie(cost, a, b) = pq.top();
		pq.pop();
		if (chk[b])
			continue;
		ans += cost;
		cnt++;
		chk[b] = 1;
		for (auto nxt : adj[b])
		{
			if (!chk[nxt.second])
				pq.push({ nxt.first,b,nxt.second });
		}

	}
	cout << ans;
}