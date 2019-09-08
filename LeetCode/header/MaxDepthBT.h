class MaxDepthBTSolution {
public:
	int maxDepth(TreeNode* root) {
		return traversal(root, 0);
	}

	int traversal(TreeNode* n, int level) {

		if (n == NULL) return level;
		level += 1;
		int left = traversal(n->left, level);
		int right = traversal(n->right, level);

		return max(left, right);

	}
};