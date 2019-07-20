



class LRUCache {
public:
	LRUCache(int capacity) {
		this->limit = capacity;
		
	}

	int get(int key) {
		int goal = -1;
		int s = this->Q.size();
		for (int i = 0; i < s; i++){
			int temp = this->Q.back();
			this->Q.pop_back();
			if (temp != key) { this->Q.push_front(temp); }
			else { goal = temp; }
		}
		if (goal != -1) {
			this->Q.push_front(goal);
			return this->M[goal];
		}
		return -1;
		
	}

	void put(int key, int value) {
		auto it = this->M.find(key);
		if (it == this->M.end()) {
			if (this->Q.size() < this->limit) {
				this->Q.push_front(key);
				this->M[key] = value;
			}
			else {
				int rm = this->Q.back();
				this->M.erase(rm);
				this->Q.pop_back();
				this->Q.push_front(key);
				this->M[key] = value;
			}
		}
		else {
			this->M[key] = value;
		}
		
	}

private:
	size_t limit;
	deque<int> Q;
	map<int, int> M;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */