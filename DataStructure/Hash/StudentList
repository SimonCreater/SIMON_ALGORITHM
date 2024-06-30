#include<iostream>
#include<string>
using namespace std;
struct entry {
	int key;
	string value;
	int valid;
	int attendence;
	entry() {

	}
	entry(int key, string value) {
		attendence = 0;
		this->key = key;
		this->value = value;
		valid = 1;
	}
	void erase() {
		valid = 2;
	}
};
int StringToInt(string name) {
	int a = 1;
	int key = 0;
	for (int i = 0; i < name.size(); i++) {
		key += (name[i] - 'a')*a;
		a *= 26;
	}
	return key;
}
class hashTable {
public:
	entry* table;
	int capacity;
	hashTable() {
		capacity = 500000;
		table = new entry[capacity];
	}
	int hashFnc(int key) {
		return key % capacity;
	}
	void add(int key, string value) {
		int probe = 1;
		int index = hashFnc(key);
		while (probe <= capacity && table[index].valid == 1) {
			probe++;
			index = hashFnc(index + 1);
		}
		if (probe > capacity)
			return;
		table[index] = entry(key, value);

	}
	void remove(int key) {
		int probe = 1;
		int index = hashFnc(key);
		while (probe <= capacity && table[index].valid !=0) {
			if (table[index].valid == 1 && table[index].key == key) {
				table[index].erase();
				return;
			}
			probe++;
			index = hashFnc(index + 1);
		}
		if (probe > capacity)
			return;
		
	}
	string name(int key) {
		int probe = 1;
		int index = hashFnc(key);
		while (probe <= capacity && table[index].valid != 0) {
			if (table[index].valid == 1 && table[index].key == key) {
				
				return table[index].value;
			}
			probe++;
			index = hashFnc(index + 1);
		}
		return "";
	}
	void setAttendance(int key) {
		int probe = 1;
		int index = hashFnc(key);
		while (probe <= capacity && table[index].valid != 0) {
			if (table[index].valid == 1 && table[index].key == key) {
				table[index].attendence += 1;
				cout << table[index].attendence << '\n';
				return;
			}
			probe++;
			index = hashFnc(index + 1);
		}
		cout << -1 << '\n';
	}
	void Count(int key) {
		int probe = 1;
		int index = hashFnc(key);
		while (probe <= capacity && table[index].valid != 0) {
			if (table[index].valid == 1 && table[index].key == key) {
				cout << table[index].attendence << '\n';
				return;
			}
			probe++;
			index = hashFnc(index + 1);
		}
		cout << -1 << '\n';
	}

};
int main() {
	int n;
	cin >> n;
	hashTable htName;
	hashTable htNum;
	for (int i = 0; i < n; i++) {
		int key;
		string name, cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> key >> name;
			htNum.add(key, name);
			htName.add(StringToInt(name),to_string(key));
		}
		else if (cmd == "delete") {
			cin >> key;
			string c = htNum.name(key);
			htNum.remove(key);
			htName.remove(StringToInt(c));
		}
		else if (cmd == "name") {
			cin >> key;
			cout << htNum.name(key) << '\n';
		}
		else if (cmd == "number") {
			cin >> name;
			if (htName.name(StringToInt(name)) == "") {
				cout << 0 << '\n';
			}
			else {
				cout << htName.name(StringToInt(name)) << '\n';
			}
		}
		else if (cmd == "present") {
			cin >> name;
			
			htName.setAttendance(StringToInt(name));
			
		}
		else if (cmd == "count") {
			cin >> key;
			string a = htNum.name(key);
			htName.Count(StringToInt(a));
		}
	}
}
