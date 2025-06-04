#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
	int capacity;
	list<pair<int, int>> lruList;
	unordered_map<int, list<pair<int, int>>::iterator> cache;

	void moveToFront(int key, int value) {
		// Remove existing entry and insert updated one at front
		lruList.erase(cache[key]);
		lruList.push_front({key, value});
		cache[key] = lruList.begin();
	}

public:
	LRUCache(int cap) : capacity(cap) {}

	int get(int key) {
		if (cache.find(key) == cache.end())
			return -1;

		int value = cache[key]->second;
		moveToFront(key, value);  // Mark as recently used
		return value;
	}

	void put(int key, int value) {
		if (cache.find(key) != cache.end()) {
			moveToFront(key, value);
		} else {
			if (lruList.size() == capacity) {
				// Remove least recently used item
				int lruKey = lruList.back().first;
				lruList.pop_back();
				cache.erase(lruKey);
			}
			lruList.push_front({key, value});
			cache[key] = lruList.begin();
		}
	}
};

int main() {
	LRUCache lru(2);
	lru.put(1, 1);
	lru.put(2, 2);
	cout << lru.get(1) << endl;  // returns 1
	lru.put(3, 3);               // evicts key 2
	cout << lru.get(2) << endl;  // returns -1 (not found)
	lru.put(4, 4);               // evicts key 1
	cout << lru.get(1) << endl;  // returns -1 (not found)
	cout << lru.get(3) << endl;  // returns 3
	cout << lru.get(4) << endl;  // returns 4
}

