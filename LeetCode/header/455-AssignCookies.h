class AssignCookiesSolution {
public:
	struct comp {
		bool operator() (const int lhs, const int rhs) {
			return lhs < rhs;
		}
	};

	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end(), comp());
		sort(s.begin(), s.end(), comp());

		int j = 0;
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (j > g.size() - 1) break;
			if (s[i] >= g[j]) {
				j++;
				count++;
			}
		}

		return count;
	}
};