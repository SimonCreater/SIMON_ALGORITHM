#include<iostream>
#include<string>
#include<vector>
using namespace std;

class minheap {
public:
	int arr[100001];
	int heapsize;
	minheap() {
		heapsize = 0;
	}
	void insert(int i) {
		arr[++heapsize] = i;
		int child = heapsize;
		int parent = child / 2;
		while (child > 1 && arr[parent] > arr[child]) {
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
			if (arr[child] > arr[child + 1]) {
				child = child + 1;
			}

		}
		while (child <= heapsize && arr[parent] > arr[child]) {
			int tmp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = tmp;
			parent = child;
			child = child * 2;
			if (child + 1 <= heapsize) {
				if (arr[child] > arr[child + 1]) {
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
	void print() {
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
	minheap h;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "empty") {
			cout << h.isEmpty() << '\n';
		}
		else if (str == "print") {
			h.print();
		}
		else if (str == "pop") {
			cout << h.pop() << '\n';
		}
		else if (str == "push") {
			int x;
			cin >> x;
			h.insert(x);
		}
		else if (str == "size") {
			cout << h.heapsize << '\n';
		}
		else if (str == "top") {
			cout << h.top() << '\n';
		}
		else if (str == "second_top") {
			h.secondTop();
		}
	}
}

