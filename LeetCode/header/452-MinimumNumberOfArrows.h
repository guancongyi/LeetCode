class MinimumNumberOfArrowsSolution {
public:
	struct comp {
		bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
			return lhs[0] < rhs[0];
		}
	};

	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.size() == 0) return 0;
		sort(points.begin(), points.end(), comp());

		int count = 1;
		vector<int> sets = points[0];
		vector<int> cur;
		for (size_t i = 1; i < points.size(); i++)
		{
			cur = points[i];
			if (cur[0] > sets[1]) {
				count++;
				sets = cur;
			}
			else {
				sets = { max(sets[0],cur[0]), min(sets[1],cur[1]) };
			}
		}

		return count;
	}
};