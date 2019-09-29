/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BTPathSolution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {

		vector<string> res;
		dfs(res, root, "");
		return res;
	}

	void dfs(vector<string>& res, TreeNode* n, string s) {
		if (n == NULL) return;
		s += to_string(n->val);

		if (n->left == NULL && n->right == NULL) res.push_back(s);
		else s += "->";

		dfs(res, n->left, s);
		dfs(res, n->right, s);



	}
};