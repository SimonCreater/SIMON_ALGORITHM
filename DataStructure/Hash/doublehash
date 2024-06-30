#include <iostream>
#include <string>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

	entry() {

	}
	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}
	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int divisor;
	int hashFnc(int key) {
		return key % capacity;
	}
	int hashFnc2(int key) {
		return divisor - (key % divisor);
	}
public:
	hashTable(int N, int M) {
		capacity = N;
		divisor = M;
		table = new entry[capacity];
		return;
	}
	void put(int key, string value) {
		int index = hashFnc(key);
		int probe = 1;
		int first = index;
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		if (probe > capacity) {
			cout << first << " " << -1 << '\n';
			return;
		}
		table[index] = entry(key, value);
		cout << first << " " << index << endl;
		return;
	}
	void erase(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				cout << table[index].value << endl;
				table[index].erase();
				return;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		cout << "None" << endl;
		return;
	}
	string find(int key) {
		int index = hashFnc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFnc(index + hashFnc2(key));
			probe++;
		}
		return "None";
	}
	void vacant() {
		int count = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM) {
				count++;
			}
		}
		cout << count << endl;
	}
};



int main() {
	int t, N, M;
	cin >> t >> N >> M;
	hashTable ht(N, M);
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		if (s == "put") {
			int key;
			string value;
			cin >> key >> value;
			ht.put(key, value);
		}
		else if (s == "erase") {
			int key;
			cin >> key;
			ht.erase(key);
		}
		else if (s == "find") {
			int key;
			cin >> key;
			cout << ht.find(key) << endl;
		}
		else if (s == "vacant") {
			ht.vacant();
		}
	}
	return 0;
}
