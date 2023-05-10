#include "iostream"
#include "vector"
#include <iostream>


class MyHashSet {
private:
	int prime;
	std::vector<std::vector<int>> table;
	
	int hash(int key) {
		return key % prime;
	}
	std::vector<int>::iterator search(int key) {
		int h = hash(key);
		return std::find(table[h].begin(), table[h].end(), key);
	}

public:
	MyHashSet() : prime(10007), table(prime) {}

	void add(int key) {
		int h = hash(key);
		if (!contains(key))
			table[h].push_back(key);
	}

	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end())
			table[h].erase(it);
	}

	bool contains(int key) {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};



int main() {
	MyHashSet ddr;
	ddr.add(4);
	ddr.add(3);
	ddr.add(2);
	ddr.add(1);
	std::cout << ddr.contains(4);
}