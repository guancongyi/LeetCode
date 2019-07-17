#include<vector>
#include<map>


using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

class SolutionTwoSum {
public:
	vector<int> twoSum1(vector<int>& nums, int target) {
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


	vector<int> twoSum2(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++){
			auto it = hash.find((target-nums[i]));
			if (it != hash.end()) {
				return{ i,it->second };
			}
			else {
				hash[nums[i]] = i;
			}
		}
		return {};
	}
};