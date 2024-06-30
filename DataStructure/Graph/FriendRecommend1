#include <iostream>
using namespace std;

int graph[501][501];
bool link[501][501];
int n, m, d;
int main() {
	cin >> n >> m >> d;
	while (d--) {
		int a, b;
		cin >> a >> b;
		link[a][b] = true;
		link[b][a] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1) {
				for (int k = 1; k <= n; k++) {
					if (k!=i&&graph[k][j] == 1 && graph[k][i] != 1) {
						graph[k][i] = 2;
						graph[i][k] = 2;
					}
				}
			}
		}
	}
	while (m--) {
		int k, s;
		cin >> k >> s;
		int sum = 0;
		int cnt = 0;
		int flag = false;
		if (s == 1) {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i]==1) {
					if (!link[k][i]) {
						cnt++;
						sum += 3;
						flag = true;
					}
					
				}
				else {
					for (int j = 1; j <= n; j++) {
						if (k != i && graph[k][j] == 1 && link[i][j]==1) {
							cnt++;
							sum += 1;
							flag = true;
						}
					}
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i] == 1) {
					if (!link[k][i]) {
						cnt++;
						sum += 3;
						flag = true;
					}

				}
				else if (graph[k][i] == 2) {
					if (!link[k][i]) {
						cnt++;
						flag = true;
						sum += 2;
					}
				}
				else {
					for (int j = 1; j <= n; j++) {
						if (k == i || !link[j][i])
							continue;
						if (graph[k][j] == 1 || graph[k][j] == 2)
						{
							cnt++;
							sum += 1;
							flag = true;
						}
					}
				}
			}
		}
		if (!flag) {
			cout << "-1";
		}
		else {
			cout << cnt << " " << sum;
		}
		cout << endl;
	}
}
