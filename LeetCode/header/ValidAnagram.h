class ValidAnagramSolution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> um;
		for (size_t i = 0; i < s.length(); i++){
			auto it = um.find(s[i]);
			if (it != um.end()) um[s[i]] += 1;
			else um[s[i]] = 1;
		}

		for (size_t j = 0; j < t.length(); j++){
			auto it = um.find(t[j]);
			if (it != um.end()) um[t[j]] -= 1;
			else return false;
		}

		for (auto k = um.begin(); k != um.end(); k++){
			if (k->second != 0) return false;
		}
		return true;
	}
};