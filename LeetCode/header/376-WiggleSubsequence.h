class WiggleSubsequenceSolution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int toggle = 2;
		int total = 0;
		if (nums.size() <= 1)return nums.size();
		for (int i = 0; i < nums.size(); i++) {
			int first = nums[i];
			int second;

			if ((i + 1) < nums.size()) second = nums[i + 1];
			else return total + 1;

			if (toggle == 2) {
				toggle = (second - first > 0) ? -1 : 1;
				if (second - first == 0) {
					toggle = 2;
					total = 0;
					continue;
				}
				total = 1;
				continue;
			}
			if (toggle == 1) {
				if (second - first > 0) {
					total++;
					toggle = -1;
				}
			}
			if (toggle == -1) {
				if (second - first < 0) {
					total++;
					toggle = 1;
				}
			}
		}

		return total + 1;
	}
};