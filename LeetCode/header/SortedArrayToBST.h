class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {

		TreeNode* root = NULL;
		return helper(nums, 0, nums.size());
	}

	TreeNode* helper(vector<int>& vec, int low, int high) {
		if (high<=low)return NULL;

		int mid = (high + low) / 2; 

		TreeNode* n = new TreeNode(vec[mid]);
		n->left = helper(vec, low, mid);
		n->right = helper(vec, mid+1, high);
		return n;

	}
};