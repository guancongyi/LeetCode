class FirstUniqCharSolution {
public:
	int firstUniqChar(string s) {
		vector<int> dict(26,-2);
		for (size_t i = 0; i < s.length(); i++){
			 
			if (dict[s[i] - 97] == -2) { dict[s[i] - 97] = i; }
			else if (dict[s[i] - 97] == -1) { continue; }
			else{ dict[s[i] - 97] = -1; }
		}

		int smallest = 100000;
		for (size_t j = 0; j < 26; j++){
			if (dict[j] != -2 && dict[j] != -1) {
				if (dict[j] < smallest) {
					smallest = dict[j];
				}
			}
		}
		if (smallest != 100000) { return smallest; }
		else return -1;
	}
};