#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector<int> adj[101];
int n;
int vis[101];
int ans[101];
int dis[101];
int dfs(int x,int y) {
	fill(vis, vis + 101, 0);
	fill(dis, dis + 101, 0);
	queue<int> s;
	s.push(x);
	vis[x] = 1;
	dis[x] = 0;
	while (!s.empty()) {
		int cur = s.front();
		s.pop();
		for (auto nxt : adj[cur]) {
			
			if (vis[nxt])
				continue;
			dis[nxt] = dis[cur] + 1;
			vis[nxt] = 1;
			if (vis[y])
				break;
			s.push(nxt);
		}
	}
	return dis[y];
}
int main() {
	int m;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i] += dfs(i, j);
	   }
	}
	//for (int i = 1; i <= n; i++) {
	//	cout << ans[i] << " ";
	//}
	//cout << '\n';

	int mins = 2000000000;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 0)
			continue;
		if (mins > ans[i])
			mins = ans[i];
	}
	for (int i = 1; i <= n; i++) {
		if (ans[i] == mins) {
			cout << i;
			break;
		}
	}
	
}
