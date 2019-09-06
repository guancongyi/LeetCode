class ValidWordAbbrSolution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int i = 0;
		
		for (int j = 0; j < abbr.length(); j++) {
			char curW = word[i];
			char curA = abbr[j];
			if (isalpha(curA)) {
				if (curA != curW) return false;
				i++;
			}

			string count = "";
			if (isdigit(curA)) {
				while (j < abbr.length() && isdigit(curA)) { 
					count += curA;
					j++;
					curA = abbr[j];
				}
				j--;

				if (count[0] == '0') return false;

				if (count != "" )i += stoi(count);
				else i++;
				
				
			}
			if (i > word.length()) return false;
			
		}
		if (i != word.length()) return false;
		return true;
	}
};