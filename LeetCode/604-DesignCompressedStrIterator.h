class StringIterator {
public:
	queue<pair<char,int>> q;

	StringIterator(string compressedString) {
		queue<pair<char, int>> empty;
		std::swap(q, empty);
		for (size_t i = 0; i < compressedString.length(); i++){
			char cur = compressedString[i];
			if (isalpha(cur)) {
				string val = "";
				i++;
				while ((i < compressedString.length()) && isdigit(compressedString[i])) {
					val += compressedString[i];
					i++;
				}
				int count = stoi(val);
				if(count>0) q.push({ cur,count });

				i--;
			}
		}
	}

	char next() {
		if (q.size() == 0) return' ';
		
		auto temp = q.front().first;
		q.front().second -= 1;
		if(q.front().second == 0) q.pop();
		return temp;
	}

	bool hasNext() {
		if (q.size() == 0) return false;
		return true;
	}

private:
	
	
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */