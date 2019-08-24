class MaxSubArraySolution {
public:
	int maxSubArrayMy(vector<int>& nums) {
		int n = nums.size();
		vector<int> vec(n);

		for (int i = 0; i < n; i++) {
			vector<int> temp(n - i);
			for (int j = 0; j < n - i; j++) {
				if (j == 0) temp[0] = nums[i];
				else { temp[j] = temp[j - 1] + nums[j + i]; }
			}
			auto it = max_element(begin(temp), end(temp));
			vec[i] = *it;
		}


		return *max_element(begin(vec), end(vec));
	}

	int maxSubArray(vector<int>& nums) {
		int sum = 0, maxSum = INT_MIN;
		for (int num : nums) {
			sum += num;
			maxSum = max(sum, maxSum);
			if (sum < 0) { sum = 0; }
		}
		return maxSum;
	}
};