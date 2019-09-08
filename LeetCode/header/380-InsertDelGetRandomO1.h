class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		auto it = this->um.find(val);
		if (it != this->um.end()) return false;

		vec.push_back(val);
		this->um[val] = vec.size()-1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		auto it = this->um.find(val);
		if (it == this->um.end()) return false;
		int pos = it->second;
		// swap cur with last in vector
		int temp = vec[vec.size() - 1];
		swap(vec[pos], vec[vec.size() - 1]);
		vec.pop_back();

		// swap cur with last in hashmap
		auto it2 = this->um.find(temp);
		it2->second = pos;
		
		this->um.erase(val); 
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return vec[rand() % vec.size()];
	}

private:
	unordered_map<int, int> um;
	vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */