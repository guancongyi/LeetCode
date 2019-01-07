#include<vector>
#include<map>


using namespace std;

class SolutionTwoSum {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int cap = nums.size();
		map<int, int> dict;
		map<int, int> lut;
		vector<int> ret;
		vector<int> rep;
		
		for (int i = 0; i < cap; i++) {
			int val = nums[i];
			int id = i;
			lut[val] = id;
			
			int diff = target - val;

			if (diff == val) {
				if (dict[val] == 1) {
					rep.push_back(id);
					return rep;
				}
				else {
					rep.push_back(id);
				}
			}
			else if(dict[diff] == 1){
				ret.push_back(lut[diff]);
				ret.push_back(id);
				return ret;
			}
			dict[val] = 1;
		}
		return ret;
	}
};