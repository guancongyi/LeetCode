class PartitionLabelSolution {
public:
	vector<int> partitionLabels(string S) {
		map<char, int> mp;
		for (int i = 0; i < S.length(); i++) { mp[S[i]] = i; }

		vector<int> res;
		int Max = mp[S[0]];
		int count = 1;
		for (int i = 1; i < S.length(); i++) {
			if (mp[S[i]] > i) {
				Max = max(Max, mp[S[i]] - i + 1);
			}
			
			if (i == Max) {
				res.push_back(count+1);
				count = 0;
				Max = 0;
			}
			count++;
		}
		return res;
	}
};