class HouseRobberSolution {
public:
	unordered_map<int, int> um;

	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		nums.push_back(0);
		nums.push_back(0);
		return opt(nums, nums.size() - 1);
	}

	int opt(vector<int>& nums, int id) {
		int s = 0;
		if (id == 0 || id == 1) return nums[id];

		if (um.find(id) == um.end()) {
			if (id > 0) s += nums[id] + max(opt(nums, id - 2), opt(nums, id - 3));
			else return 0;
			um[id] = s;
			return s;
		}
		return um[id];
	}
};