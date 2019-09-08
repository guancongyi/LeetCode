class ValidWordSquareSolution {
public:
	bool validWordSquare(vector<string>& words) {
		if (words.size() == 0) return true;
		for (int i = 0; i < words.size(); i++) {
			string str = words[i];
			for (int j = 0; j < str.length(); j++) {
				if (j >= words.size()) return false;
				try {
					if (words[i].at(j) != words[j].at(i)) return false;
				}
				catch (const out_of_range& oor) {
					return false;
				}

			}
		}
		return true;
	}
}; 
