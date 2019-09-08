class InorderSuccessorInBSTSolution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		vector<int> v;
		TreeNode* ret = NULL;
		InorderTrav(root,v);
		for (size_t i = 0; i < v.size(); i++){
			if (v[i] == p->val) 
				if ((i + 1) < v.size()) { ret =new TreeNode(v[i + 1]); }
		}
		return ret;
	}

	void InorderTrav(TreeNode* n, vector<int>& v) {
		if (n == NULL) return;
		if (n->left != NULL) {
			InorderTrav(n->left, v);
		}
		v.push_back(n->val);
		if (n->right != NULL) {
			InorderTrav(n->right, v);
		}
	}
};