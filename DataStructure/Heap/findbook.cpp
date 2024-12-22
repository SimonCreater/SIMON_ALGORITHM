#include<iostream>
#include<string>
#include<vector>
using namespace std;
int compare1(int a1, int a2) {
	if (a1 % 2 == 1 && a2 % 2 == 0)
		return 1;
	else if (a1 % 2 == 1 && a2 % 2 == 1) {
		if (a1 > a2)
			return 1;
		else
			return 0;
	}
	else if (a1 % 2 == 0 && a2 % 2 == 0)
	{
		if (a1 < a2)
			return 1;
		else
			return 0;
	}
	else return 0;
}
class minheap {
public:
	int arr[10001];
	int heapsize;
	minheap() {
		heapsize = 0;
	}
	void insert(int i) {
		arr[++heapsize] = i;
		int child = heapsize;
		int parent = child / 2;
		
		while (child > 1 && compare1(arr[child], arr[parent]) == 1) {

			int tmp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = tmp;
			
			child = parent;
			parent = child / 2;

		}


	}
	int pop() {
		if (heapsize == 0)
			return -1;
		int result = arr[1];
		arr[1] = arr[heapsize];
		heapsize--;
		int parent = 1;
		int child = parent * 2;
		if (child + 1 <= heapsize) {
			if (compare1(arr[child + 1], arr[child]) == 1) {
				child = child + 1;
			}

		}
		while (child <= heapsize && compare1(arr[child], arr[parent]) == 1) {
			int tmp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = tmp;
			parent = child;
			child = child * 2;
			if (child + 1 <= heapsize) {
				if (compare1(arr[child + 1], arr[child]) == 1) {
					child = child + 1;
				}

			}
		}
		return result;
	}
	int isEmpty() {
		if (heapsize == 0)
			return true;
		else
			return false;
	}
	int top() {
		if (heapsize == 0)
			return -1;
		else
			return arr[1];
	}
	void secondTop() {
		if (heapsize < 2)
			cout << "Error" << '\n';
		else if (heapsize == 2) {
			cout << arr[heapsize] << '\n';
		}
		else {
			if (arr[2] > arr[3])
				cout << arr[3] << '\n';
			else
				cout << arr[2] << '\n';
		}
	}
	void Print() {
		if (heapsize == 0)
			cout << -1 << "\n";
		else
		{
			for (int i = 1; i <= heapsize; i++) {
				cout << arr[i] << " ";
			}
		}
	}
	int size() {
		return heapsize;
	}
};
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		minheap h;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			h.insert(x);
		}
		while (h.heapsize != 0) {
			cout << h.pop() << " ";
		}
		cout << '\n';
	}
}

