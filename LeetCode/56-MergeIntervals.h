struct comp {
	bool operator() (const vector<int>& lhs,const vector<int>& rhs) {
		return lhs[0] < rhs[0];
	}
};

class MergeIntervalsSolution {
public:

	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		vector<vector<int>> res;
		if (intervals.size() == 0)return res;
		if (intervals.size() == 1)return intervals;

		sort(intervals.begin(), intervals.end(), comp());
		vector<int> last = intervals[0];
		res.push_back(last);

		for (int i = 1; i < intervals.size(); i++){
			vector<int> cur = intervals[i];
			// case 1. cur small > last large, 2 sets
			if (cur[0] > last[1]) { 
				res.push_back(cur);
				last = cur;
			}
			// case 2. intersect or included
			if (cur[0] <= last[1]) { 
				res.pop_back();
				res.push_back({ min(cur[0],last[0]), max(cur[1],last[1]) });
				last = { min(cur[0],last[0]), max(cur[1],last[1]) };
			}

		}
		
		return res;
	}
};