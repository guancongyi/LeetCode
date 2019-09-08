class CountBtNodesSolution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		return helper(root);
	}


	int helper(TreeNode* n) {
		int count = 1;
		if (n == NULL) return count;
		if (n->left != NULL) count += helper(n->left);
		if (n->right != NULL) count += helper(n->right);
		return count;
	}
};
