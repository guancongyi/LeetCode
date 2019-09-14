#ifndef PS
#define PS
class PartitionLabelSolution {
public:
	vector<int> partitionLabels(string S) {
		map<char, int> mp;

		for (int i = 0; i < S.length(); i++) { mp[S[i]] = i; }

		vector<int> res;
		int Max = mp[S[0]];
		int count = 0;
		for (int i = 0; i < S.length(); i++) {
			if (mp[S[i]] >= i) {
				Max = max(Max, mp[S[i]]);
			}

			if (i == Max) {
				res.push_back(count + 1);
				count = -1;
			}
			count++;
		}
		return res;
	}
};
#endif // !1


