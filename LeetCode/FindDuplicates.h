/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?


Solution:
[4,3,2,7,8,2,3,1]

switch each number to its position until there's
a duplicate


123454
*/

class FindDuplicatesSolution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ret;
		int id = 0;
		while (id < nums.size()) {

			int a = nums[id];
			if (a == -1) {
				id++;
				continue;
			}
			int b = nums[a-1];
			if (a == b ) {
				if (id == a - 1) {
					id++;
					continue;
				}
				else {
					nums[a - 1] = -1;
					ret.push_back(a);
					id++;
				}
				
			}
			else {
				nums[id] = b;
				nums[a-1] = a;
			}
			
		}
		return ret;
	}


};