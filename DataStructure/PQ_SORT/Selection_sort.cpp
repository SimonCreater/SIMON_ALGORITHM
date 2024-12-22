#include<iostream>
#include<vector>
using namespace std;
struct compare {
	bool operator()(const int& a1, const int& a2) {
		if (a1 < a2)
			return true;
		else
			return false;
	}
};
class PQ {
private:
	vector<int> sq;
public:
	void insert(int x) {
		compare c;
		int i = 0;
		for (; i < sq.size(); i++) {
			if (c(sq[i], x)) {
				break;
			}
		}
		sq.insert(sq.begin() + i, x);
	}
	int min() {
		if (sq.empty())
			return -1;
		else
			return sq.back();
	}
	void removeMin() {
		if (sq.empty())
			return;
		else
			sq.pop_back();
	}
};
int main() {
	int t, n;
	int lis[20];
	int ans[20];
	PQ p;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> lis[i];
		}
		for (int i = 0; i < n; i++) {
			p.insert(lis[i]);
		}
		for (int i = 0; i < n; i++) {
			ans[i] = p.min();
			p.removeMin();
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		int a = ans[0];
		for (int i = 1; i < n; i++) {
			cout << ans[i] + a << " ";
		}
		cout << endl;
	}
}
