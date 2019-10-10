class ClimbingStairSolution {
public:
	unordered_map<int, int> mp;
	int climbStairs(int n) {

		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;


		if (mp.find(n) == mp.end()) {
			mp[n] = climbStairs(n - 2) + climbStairs(n - 1);
		}

		return mp[n];


	}
};