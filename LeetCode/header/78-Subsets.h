/*
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


method:
add each number one at a time iteratively!!!
-.-
*/

class Subsets {
public:
	vector<vector<int>> subsetss(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> empty;
		ret.push_back(empty);

		int len = nums.size();
		for (size_t i = 0; i < len; i++)
		{
			vector<int> curr;
			curr.push_back(nums[i]);
			if (ret.size() == 1) {
				ret.push_back(curr);
			}
			else {
				
				int l = ret.size();
				for (size_t j = 0; j < l; j++){
					vector<int> temp = ret[j];
					temp.push_back(nums[i]);
					ret.push_back(temp);
				}
				
			}
		}
		return ret;
	}


};

class Subsets1_2 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		bt(res, nums, temp, 0);
		return res;
	}

	void bt(vector<vector<int>>& v, vector<int>& nums, vector<int> temp, int id) {
		v.push_back(temp);
		for (int i = id; i < nums.size(); i++) {
			temp.push_back(nums[i]);
			bt(v, nums, temp, i + 1);
			temp.pop_back();
		}
				
	}


};