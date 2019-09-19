class Solution {
public:
	int numSquares(int n) {
		vector<int> all;
		all.push_back(1);
		int now = 1;
		int N = 1;

		while (true) {
			all.push_back(now + 2 * N + 1);
			now = now + 2 * N + 1;
			if (now > N) break;
			N++;
		}

	}
};