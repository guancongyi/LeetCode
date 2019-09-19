class NonOverlappingSolution {
public:
	struct comp {
		bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
			return lhs[1] < rhs[1];
		}
	};

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), comp());
		vector<int> last = intervals[0];
		int count = 0;
		for (size_t i = 1; i < intervals.size(); i++)
		{
			vector<int> cur = intervals[i];
			if (cur[0] >= last[1]) {
				last = cur;
			}
			else {
				count++;
			}

		}
		return count;
	}
};