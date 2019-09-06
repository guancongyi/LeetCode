class ValidWordAbbrSolution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int i = 0;
		char curW = word[i];
		for (int j = 0; j < abbr.length(); j++) {
			char curA = abbr[j];
			if (isalpha(curA)) {
				if (curA != curW) return false;
				i++;
			}

			string count = "";
			if (isdigit(curA)) {

				while (j < abbr.length() && isdigit(curA)) {
					if (curA == '0') { j++; continue; }
					count += curA;
					j++;
					curA = abbr[j];
				}
				cout << count;
				j--;
				if (count != "")i += stoi(count);
				else i++;
			}
			//cout << i << " "<< j << " "<<endl;

			if (i > word.length()) return false;
			else curW = word[i];

		}
		if (i != word.length()) return false;
		return true;
	}
};