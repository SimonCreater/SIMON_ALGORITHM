#include<iostream>
using namespace std;
int graph[501][501];
int reject[501];
int main() {
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < d; i++) {
		int x;
		cin >> x;
		reject[x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j]==1) {
				for (int k = 1; k <= n; k++) {
					if (k != i && graph[k][j] == 1 && graph[k][i] != 1) {
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
		int cnt = 0, sum = 0;
		bool flag = false;
		if (s == 1) {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i]==1) {
					if (!reject[i]) {
						sum+=2;
						cnt++;
						flag = true;
					}
					
				}
			}
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (graph[k][i]==1) {
					if (!reject[i]) {
						sum += 2;
						cnt++;
						flag = true;
					}

				}
				else if (graph[k][i] == 2) {
					if (!reject[i]) {
						sum += 1;
						cnt++;
						flag = true;
					}
				}

			}
		}
		if (!flag) {
			cout << -1;
		}
		else
			cout << cnt << " " << sum;
		cout << '\n';
	}
}
