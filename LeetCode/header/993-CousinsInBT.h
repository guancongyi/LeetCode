class CousinsInBTSolution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (root == NULL) return false;
		vector<pair<int, int>> vec; //<parent, level>
		int level = 0;

		helper(root, x, y, level, 0, vec);
		if (vec[0].first != vec[1].first && vec[0].second == vec[1].second) return true;
		return false;
	}

	void helper(TreeNode* n, int x, int y, int h, int parent, vector<pair<int, int>>& v) {
		if (n == NULL) return;
		if (n->val == x || n->val == y) v.push_back({ parent, h });

		h += 1;
		helper(n->left, x, y, h, n->val, v);
		helper(n->right, x, y, h, n->val, v);

	}

};