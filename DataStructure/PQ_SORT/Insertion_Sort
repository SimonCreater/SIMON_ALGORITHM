#include<iostream>
#include<vector>
using namespace std;
struct compare {
	bool operator()(const int &a1,const int &a2) {
		if (a1 % 5 == 0 && a2 % 5 != 0)
			return true;
		else if (a1 % 5 != 0 && a2 % 5 == 0)
			return false;
		else
			return a1 > a2;
	}
};
class PQ {
private:
	vector<int> sq;
public:
	void insert(int x) {
		sq.push_back(x);
	}
	int min() {
		if (sq.empty())
			return -1;
		int a = sq[0];
		compare c;
		for (int i = 0; i < sq.size(); i++) {
			if (c(sq[i], a)) {
				a = sq[i];
			}
		}
		return a;
	}
	void removeMin() {
		compare c;
		int mindex = 0;
		for (int i = 0; i < sq.size(); i++) {
			if (c(sq[i], sq[mindex]))
				mindex = i;
		}
		sq.erase(sq.begin() + mindex);
	}
};
int main() {
	int t;
	cin >> t;
	PQ q;
	while (t--) {
		int n;
		cin >> n;
		int lis[20];
		for (int i = 0; i < n; i++) {
			cin >> lis[i];
		}
		for (int i = 0; i < n; i++) {
			q.insert(lis[i]);
		}
		for (int i = 0; i < n; i++) {
			cout << q.min() << " ";
			q.removeMin();
		}
		cout << endl;
	}
}
