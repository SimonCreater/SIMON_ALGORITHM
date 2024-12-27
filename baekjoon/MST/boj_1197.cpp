#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
vector<int> p(10005, -1);
int find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return 0;
	if (p[u] == p[v])
		p[u]--;
	if (p[u] < p[v])
		p[v] = u;
	else
		p[u] = v;
	return 1;
}
tuple<int, int, int> edge[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c,a,b };
	}
	sort(edge, edge + m);
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		tie(c, a, b) = edge[i];
		if (!is_diff_group(a, b))
			continue;
		ans += c;
		cnt++;
		if (cnt == m - 1)
			break;
	}
	cout << ans;
}