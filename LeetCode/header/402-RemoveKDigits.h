class RemoveKDigitsSolution {
public:
	string removeKdigits(string num, int k) {
		if (num.length() == k) return "0";
		int count = 0;

		stack<char> s;
		s.push(num[0]);
		
		for (int i = 1; i < num.size(); i++) {
			while (!s.empty() && num[i] < s.top() && k !=0) {
				s.pop();
				k--;
			}
			s.push(num[i]);
		}

		while (k != 0) { s.pop(); k--; }
		string res = "";
		while (!s.empty()) {
			res += s.top();
			s.pop();
		}

		reverse(res.begin(), res.end());

		auto found = res.find_first_not_of('0');
		if (found != std::string::npos) {
			res = res.substr(found, res.size() - found);
		}
		else return "0";
		return res;
	}
};