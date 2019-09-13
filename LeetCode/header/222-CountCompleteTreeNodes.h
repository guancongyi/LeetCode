class CountCompleteTreeNodesSolution {
public:
	int countNodes1(TreeNode* root) {
		if (root == NULL) return 0;
		return helper1(root);
	}


	int helper1(TreeNode* n) {
		int count = 1;
		if (n == NULL) return count;
		if (n->left != NULL) count += helper1(n->left);
		if (n->right != NULL) count += helper1(n->right);
		return count;
	}

};