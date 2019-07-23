/*
containers:
table with <int, Node*> that can store each element in the list
table with <Node*, Node*> that can store each element's parent
table with <int, int> that can store each key-value .

There is another way of doing it.
*/




class LRUCache {
public:
	LRUCache(int capacity) {
		this->limit = capacity;
		this->size = 0;
		this->head = NULL;
		this->last = NULL;

	}

	int get(int key) {
		auto it = this->vals.find(key);
		int ret = -1;
		if (it != this->vals.end()) {
			ret = this->vals[key];
			put(key, ret);
		}
		return ret;
	}

	void put(int key, int value) {
		if (this->size == 0) {
			Node* temp = new Node(key, NULL, NULL);
			this->head = temp;
			this->last = temp;

			this->vals[key] = value;
			this->table[key] = temp;
			this->before[temp] = NULL;
			
			this->size++;
		}
		else {
			auto it = this->vals.find(key);
			// already exist
			if (it != this->vals.end()) {
				this->vals[key] = value;
				if (this->table[key] == last) {
					// do nothing but update values
				}
				// in the head, in the middle, or at the end
				else if (this->table[key] == head) {
					// update head
					Node* oldHead = this->head;
					this->head = this->head->next;
					this->before[this->head] = NULL;
					this->table[this->head->val] = this->head;
					oldHead->next = NULL;

					// attach new node to the end of the list
					this->last->next = oldHead;
					this->table[key] = oldHead;
					this->before[oldHead] = this->last;
					this->last = this->last->next;
				}
				
				else {
					Node* cur = this->table[key];
					Node* oneBf = this->before[cur];
					// rematch the one before
					oneBf->next = cur->next;
					
					// update maps
					this->before[cur->next] = oneBf;

					// attach new node to the end of the list
					cur->next = NULL;
					this->last->next = cur;
					this->table[key] = cur;
					this->before[cur] = this->last;
					this->last = this->last->next;
				}
			}
			// otherwise not exist
			else {
				this->vals[key] = value;

				Node* temp = new Node(key, NULL, NULL);
				this->last->next = temp;

				this->before[temp] = this->last;
				this->table[key] = temp;
				this->last = this->last->next;

				this->size++;

				if (this->size > this->limit) {
					Node* oldHead = this->head;
					this->head = this->head->next;
					this->before[this->head] = NULL;
					
					
					this->vals.erase(oldHead->val);
					this->before.erase(oldHead);
					this->table.erase(oldHead->val);
					delete oldHead;
					this->size--;
				}
				
				
				
			}
		}
		
		
		
	}

private:
	size_t limit, size;
	Node* head ,*last;
	unordered_map<int, Node*> table;
	unordered_map<Node*, Node*> before;
	map<int, int> vals;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */