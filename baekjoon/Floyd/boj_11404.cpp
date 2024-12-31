#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int d[105][105];
const int INF = 0x3f3f3f3f;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;

	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF)
				cout << "0 ";
			else
				cout << d[i][j] << " ";

		}
		cout << '\n';
	}
}