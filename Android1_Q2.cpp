#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
	static const int SIZE = 10007;  // A prime number to reduce collisions
	vector<pair<int, int>> table[SIZE];  // Array of vectors as buckets

	int hash(int key) {
		return key % SIZE;
	}

public:
	MyHashMap() {}

	void put(int key, int value) {
		int idx = hash(key);
		for (auto& p : table[idx]) {
			if (p.first == key) {
				p.second = value;  // Update
				return;
			}
		}
		table[idx].emplace_back(key, value);  // Insert new
	}

	int get(int key) {
		int idx = hash(key);
		for (auto& p : table[idx]) {
			if (p.first == key) return p.second;
		}
		return -1;  // Not found
	}

	void remove(int key) {
		int idx = hash(key);
		auto& bucket = table[idx];
		for (auto it = bucket.begin(); it != bucket.end(); ++it) {
			if (it->first == key) {
				bucket.erase(it);
				return;
			}
		}
	}
};

int main() {
	MyHashMap obj;
	obj.put(1, 10);
	obj.put(2, 20);
	cout << obj.get(1) << endl;  // returns 10
	cout << obj.get(3) << endl;  // returns -1 (not found)
	obj.put(2, 30);              // update key 2
	cout << obj.get(2) << endl;  // returns 30
	obj.remove(2);
	cout << obj.get(2) << endl;  // returns -1 (removed)
}
