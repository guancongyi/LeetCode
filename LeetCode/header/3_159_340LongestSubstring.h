// 3
class LongestSubStringSolution {
public:
	int lengthOfLongestSubstring(string s) {
		map<int, int> mp;
		int start = -1;
		int best = 0;
		for (int i = 0; i < s.length(); i++){
			if (mp.find(s[i]) != mp.end() && start<mp[s[i]]) {
				start = mp[s[i]] ;
			}
			else {
				best = std::max(best, i - start);
			}
			mp[s[i]] = i;

		}
		return best;
	}

	int lengthOfLongestSubstringKDistinct(string s, int k) {
		map<char, int> mp;
		int start = -1;
		int best = 0;

		if (k == 0) return 0;
		for (int i = 0; i < s.length(); i++) {
			if (mp.find(s[i]) != mp.end() && start < mp[s[i]]) {
				start = mp[s[i]];
				mp[s[i]] = i;
			}
			else {
				if (mp.size() < k) {
					mp[s[i]] = i;
				}
				else {
					mp.erase(mp[s[i]]);
					start = mp[s[i]];
					best = std::max(best, i - start);
				}
			}
			
			
		}
		return best;
	}
};