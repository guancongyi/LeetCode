class SymmericTreeSolution {
public:
	bool isSymmetric(TreeNode* root) {
		stack<TreeNode*> s;
		if (root == NULL)return true;
		s.push(root->right);
		s.push(root->left);

		while (!s.empty()) {
			TreeNode* n1 = s.top();
			s.pop();
			TreeNode* n2 = s.top();
			s.pop();
			if ((n1 == NULL && n2 != NULL) || (n2 == NULL && n1 != NULL)) return false;
			if (n1 != NULL && n2 != NULL) {
				if (n1->val != n2->val) return false;
				else {
					s.push(n1->left);
					s.push(n2->right);
					s.push(n1->right);
					s.push(n2->left);
				}
			}
		}
		return true;
	}

	bool isSymmetric2(TreeNode* root) {
		if (root == NULL)return true;
		bool res = true;
		helper(root->left, root->right, res);
		return res;

	}

	void helper(TreeNode* l, TreeNode* r, bool &res) {
		if (l == NULL && r == NULL) return;
		if ((l == NULL && r != NULL) || (l != NULL && r == NULL)) {
			res = false; return;
		}
		if (l->val != r->val) res = false;
		helper(l->left, r->right, res);
		helper(l->right, r->left, res);
	}

};