class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		this->flag = 1;
	}

	void push(int x) {
		if (this->flag == 1) { this->flag = 0; this->min = x; }

		if (x < this->min) { 
			this->min = x;
			this->s.push({ x, this->min }); }
		else {
			this->s.push({ x, this->min });
		}
	}

	void pop() {
		this->s.pop();
		if (this->s.size() == 0) { this->flag = 1; }
		else{ this->min = this->s.top().second; }
		
	}

	int top() {
		return this->s.top().first;
	}

	int getMin() {
		if (this->s.size() == 0) { return NULL; }
		return this->s.top().second;
	}
private:
	stack<pair<int, int>> s;
	int min;
	int flag;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */