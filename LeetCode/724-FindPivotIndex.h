class FindPivotSolution {
public:
	int pivotIndex(vector<int>& nums) {
		int right = accumulate(nums.begin(), nums.end(), 0);
		int left = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i != 0) left += nums[i - 1];
			right -= nums[i];
			if (left == right) return i;
		}

		return -1;
	}
};