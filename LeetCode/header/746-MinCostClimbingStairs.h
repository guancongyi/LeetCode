class MinCostClimbingStairSolution {
public:
	unordered_map<int, int> um;
	int minCostClimbingStairs(vector<int>& cost) {
		cost.push_back(0);
		int n = cost.size() - 1;
		um[-1] = 0; um[0] = cost[0]; um[1] = cost[1];
		return findMin(cost, n);
	}

	int findMin(vector<int>& c, int n) {
		if (n == -1 || n == 0 || n == 1)return um[n];
		if (um.find(n) == um.end()) {
			int res = min(findMin(c, n - 1) + c[n], findMin(c, n - 2) + c[n]);
			um[n] = res;
		}

		return um[n];
	}
};