#include<iostream>
#include<string>
using namespace std;
int graph[10001][10001];
int vertex[10001];
int degree[10001];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string cmd;
		cin >> cmd;
		int s, d;
		if (cmd == "minVertexInfo") {
			int min = 10001;
			bool flag = false;
			for (int i = 0; i < 10001; i++) {
				if (vertex[i]) {
					min = i;
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << -1 << '\n';
			}
			else
				cout << min << " " << degree[min] << '\n';
		}
		else if (cmd == "insertVertex") {
			cin >> s;
			if (vertex[s]) {
				cout << "Exist" << '\n';
			}
			else {
				vertex[s] = 1;
			}
		}
		else if (cmd == "insertEdge") {
			cin >> s >> d;
			if (graph[s][d]) {
				cout << "Exist" << '\n';
			}
			else {
				graph[s][d] = 1;
				graph[d][s] = 1;
				degree[s] += 1;
				degree[d] += 1;
			}
		}
		else if (cmd == "eraseVertex") {
			cin >> s;
			vertex[s] = 0;
			for (int i = 1; i < 10001; i++) {
				if (graph[s][i]) {
					graph[s][i] = 0;
					graph[i][s] = 0;
					degree[s] -= 1;
					degree[i] -= 1;
				}
			}
		}
		else if (cmd == "eraseEdge") {
			cin >> s >> d;
			if (!graph[s][d]) {
				cout << "None" << '\n';

			}
			else {
				graph[s][d] = 0;
				graph[d][s] = 0;
				degree[s] -= 1;
				degree[d] -= 1;
			}

		}
		else if (cmd == "isAdjacent") {
			cin >> s >> d;
			int min;
			if (graph[s][d]) {
				cout << "True" << " ";
				if (degree[s] > degree[d]) {
					min = d;
				}
				else if (degree[s] < degree[d]) {
					min = s;
				}
				else {
					if (s > d) {
						min = d;
					}
					else
						min = s;
				}
				cout << min << '\n';
			}
			else {
				cout << "False" << " ";
				if (degree[s] > degree[d]) {
					min = d;
				}
				else if (degree[s] < degree[d]) {
					min = s;
				}
				else {
					if (s > d) {
						min = d;
					}
					else
						min = s;
				}
				cout << min << '\n';
			}
		}
		
	}
}
