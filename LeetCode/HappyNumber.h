class HappySolution {
public:
	bool isHappy(int n) {
		string num = to_string(n);
		unordered_map<int, int> um;
		while (true) {
			int sum = 0;
			for (size_t i = 0; i < num.length(); i++) {
				sum += pow((num[i] - '0'),2);
			}
			if (sum == 1) return true;
			auto it = um.find(sum);
			if (it == um.end()) { um[sum] += 1; }
			else { return false; }
			
			num = to_string(sum);
		}
		
	}
};
