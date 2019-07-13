class MovingAverage {
public:
	/** Initialize your data structure here. */

	MovingAverage(int size) {
		this->s = size;
	}

	double next(int val) {
		if (Q.size() < this->s) { Q.push(val); return (sum += val) / Q.size(); }
		else {
			sum -= Q.front();
			Q.pop();
			Q.push(val);
			return (sum += val) / this->s;
		}
	}
private:
	queue<int> Q;
	int s;
	double sum = 0;

};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */