#include<iostream>
#include<string>
using namespace std;
int num = 0;
struct  entry {
	string s;
	string p;
	int valid;
	bool log;
	entry() {
		valid = 0;
	}
	entry(string s, string p) {
		this->s = s;
		this->p = p;
		this->valid = 1;
		this->log = false;
	}

};
int StringToInt(string p) {
	int a = 1;
	int key = 0;
	for (int i = 0; i < p.size(); i++) {
		key += (p[i] - 'a') * a;
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
	void signup(string s, string p) {
		int index = hashFnc(StringToInt(s));
		int probe = 1;
		while (table[index].valid == 1 && probe <= capacity) {
			if (table[index].s == s) {
				cout << "Invalid\n";
				return;
			}
			probe++;
			index = hashFnc(index + 1);
		}
		if (capacity < probe)
			return;
		cout << "Submit" << '\n';
		table[index] = entry(s, p);

	}
	void login(string s, string p) {
		int index = hashFnc(StringToInt(s));
		int probe = 1;
		while (table[index].valid != 0 && probe <= capacity) {
			if (table[index].s == s && table[index].p == p && table[index].log == true) {

				cout << "Already\n";
				return;
			}
			else if (table[index].s == s && table[index].p == p && table[index].log == false) {
				table[index].log = true;
				num++;
				cout << "Submit\n";
				return;
			}
			probe++;
			index = hashFnc(index + 1);
		}
		cout << "Invalid" << '\n';

	}
	void logout(string s) {
		int index = hashFnc(StringToInt(s));
		int probe = 1;
		while (table[index].valid != 0 && probe <= capacity) {
			if (table[index].s == s) {
				table[index].log = false;
				num--;
				cout << "Submit\n";
				return;
			}
			probe++;
			index = hashFnc(index + 1);
		}
	}



};
int main() {
	int n;
	cin >> n;
	hashTable h;

	for (int i = 0; i < n; i++) {
		string smd;
		string s, p;
		cin >> smd;
		if (smd == "signup") {
			cin >> s >> p;
			h.signup(s, p);
		}
		else if (smd == "login") {
			cin >> s >> p;
			h.login(s, p);

		}
		else if (smd == "logout") {
			cin >> s;
			h.logout(s);

		}
		else if (smd == "online") {
			cout << num << '\n';
		}
	}
}
