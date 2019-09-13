

class QreconstructByHeightSolution {
public:

	struct comp {
		bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
			if (lhs[0] == rhs[0]) {
				return lhs[1] < rhs[1];
			}
			return lhs[0] > rhs[0];
		}
	};

	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		if (people.size() == 0)return { {} };
		sort(people.begin(), people.end(), comp());
		list<vector<int>> l;
		//map<vector<int>, list<vector<int>>::iterator> mp;

		vector<int> last = people[0];
		l.push_back(last);
		//mp[last] = l.begin();

		for (int i = 1; i < people.size(); i++){
			vector<int> cur = people[i];
			int count = 0;
			
			auto it = l.begin();
			while (count <= cur[1]) {
				if (count == cur[1]) {
					l.insert(it, cur);
					break;
				}
				it++;
				count++;
			}
			
			last = cur;
		}


		vector<vector<int>> res;
		for (auto i = l.begin(); i !=l.end(); i++){
			res.push_back(*i);
		}

		return res;
	}
};