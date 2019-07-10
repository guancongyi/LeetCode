/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?


Solution:
switch each number to its position until there's
a duplicate.

[4,3,2,7,8,2,3,1]
[7,3,2,4,8,2,3,1]
[3,3,2,4,8,2,7,1]
[2,3,3,4,8,2,7,1]
[3,2,3,4,8,2,7,1]
[x,2,x,4,8,2,7,1]

[x,2,x,4,8,2,7,1]
[x,2,x,4,8,2,7,1]

[x,2,x,4,8,2,7,1]
[x,2,x,4,8,2,7,1]

[x,2,x,4,1,2,7,8]

[1,2,x,4,x,2,7,8]
[1,x,x,4,x,x,7,8]

better solution:
negation
double negation will be positive
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
			if (id == a - 1) {
				id++;
				continue;
			}
			if (a == b ) {
				nums[a - 1] = -1;
				ret.push_back(a);
				id++;
			}
			else {
				nums[id] = b;
				nums[a-1] = a;
			}
			
		}
		return ret;
	}


};