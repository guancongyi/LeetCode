class PerfectSquareSolution {
public:
	int numSquares(int n) {
		queue<pair<int, int>> q;
		vector<int> v;
		int now = 0;
		int N = 0;

		while (true) {
			if ((now + 2 * N + 1) > n) break;
			q.push({ now + 2 * N + 1, now + 2 * N + 1 });
			v.push_back(now + 2 * N + 1);
			if (now + 2 * N + 1 == n) return 1;
			now = now + 2 * N + 1;
			N++;
		}
		q.push({ -1, -1 });

		int level = 1;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			if (cur.first == -1) {
				level++;
				q.push({ -1,-1 });
				continue;
			}

			if (cur.second < n) {
				for (size_t i = 0; i < v.size(); i++) {
					if (v[i] + cur.second > n) break;
					if (v[i] + cur.second == n) return level + 1;
					q.push({ v[i], v[i] + cur.second });
				}
			}
		}

		return 0;
	}
};