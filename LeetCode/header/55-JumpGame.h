// Find the max reachable point
// greedy

class JumpGameSolution {
public:
	bool canJump(vector<int>& nums) {
		int Max = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (Max < i) return false;
			Max = std::max(Max, i + nums[i]);
		}
		if (Max >= nums.size() - 1) return true;
		return false;
	}
};