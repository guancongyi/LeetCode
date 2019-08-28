

class KClosestPointsSolution {
public:
	class compp {
	public:
		int operator() (const vector<int>& lhs, const vector<int>& rhs) const {
			return sqrt(lhs[0] * lhs[0] + lhs[1] * lhs[1]) < sqrt(rhs[0] * rhs[0] + rhs[1] * rhs[1]);
		}
	};
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		multimap<vector<int>,int, compp > ret;
		for (int i = 0; i < points.size(); i++) {
			ret.insert({ points[i], i });
		}

		
		vector <vector<int>> res;
		for (auto j = ret.begin(); j != ret.end();j++) {
			if (K == 0) break;
			res.push_back(j->first);
			K--;
		}

		return res;
	}
};