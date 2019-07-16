/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

 Solution:
 not a good way, I used range, which is essentially the inorder traversal
 It is better to use in order traversal with a stack.
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class ValidBSTSolution {
public:
	bool isValidBST(TreeNode* root) {
		bool ret1 = true, ret2 = true;
		if (root == NULL) { return true; }
		if (root->left == NULL && root->right == NULL) { return true; }
		if (root->right != NULL) { ret1 = check(root->right, root->val, LLONG_MAX); }
		if (root->left != NULL) { ret2 = check(root->left, LLONG_MIN, root->val); }
		
		return ret1 & ret2;
	}

	bool check(TreeNode* cur, long long low, long long high) {
		if (cur != NULL) {
			if (cur->val < high && cur->val>low) {
				return (check(cur->left, low, cur->val) & check(cur->right, cur->val, high));				
			}
			else {
				return false;
			}
		}
		return true;
	}
};