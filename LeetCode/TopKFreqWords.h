
class TopKFreqWordsSolution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> mp;
		vector<vector<string>> table(words.size());
		// sort based on alphabatical order
		for (size_t i = 0; i < words.size(); i++){
			mp[words[i]] += 1;
		}

		// sort based on counts
		for (const auto &it: mp){
			if (table[it.second].size() == 0) table[it.second].push_back(it.first);
			else table[it.second].push_back(it.first);
		}

		// construct return vector
		vector<string> ret;
		for (size_t i = 0; i < table.size(); i++){
			int pos = words.size() - 1 - i;
			if (k <= 0)break;
			if (table[pos].size() != 0 ) {
				if(k>= table[pos].size()) ret.insert(ret.end(), table[pos].begin(), table[pos].end());
				else {
					for (size_t j = 0; j < table[pos].size(); j++){
						ret.push_back(table[pos][j]);
						k--;
						if (k == 0)break;
					}
				}
				k-=table[pos].size();
			}
			
		}

		return ret;
	}
};

