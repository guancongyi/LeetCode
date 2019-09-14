
bool sortBySec(pair<char, int>& a, pair<char, int>& b) {
	return a.second > b.second;
}
class ReorganizeStringSolution {
public:

	string reorganizeString(string S) {
		vector<pair<char, int>> v;
		map<char, int> mp;
		for (size_t i = 0; i < S.length(); i++){
			if (mp.find(S[i]) == mp.end()) {
				mp[S[i]] = 1;
			}
			else mp[S[i]]++; 
		}
		for (auto it = mp.begin(); it!=mp.end(); it++){
			v.push_back({ it->first, it->second });
		}

		
		sort(v.begin(), v.end(), sortBySec);
		vector<char> ret(S.length());
		int trav = 0;
		for (size_t i = 0; i < v.size(); i++){
			int count = v[i].second;
			char cur = v[i].first;
			while (count > 0) {
				if (S.length()%2 == 0){ if (count > (S.size() / 2)) return ""; }
				if (S.length() % 2 != 0) { if (count > (S.size() / 2)+1) return ""; }
				if (trav == ret.size() - 1 || trav == ret.size() - 2) {
					ret[trav] = cur;
					trav = 1;
				}
				else {
					ret[trav] = cur;
					trav += 2;
				}
				count--;
			}
		}

		string res="";
		for (size_t i = 0; i < ret.size(); i++){
			res += ret[i];
		}
		return res;

	}
};