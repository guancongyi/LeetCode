class BTLevelOrderTravSolution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vec;
		vector<int> sub_vec;
		queue<TreeNode*> q;

		if (root != NULL) { q.push(root); q.push(NULL); }
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();

			if (cur == NULL) {
				if (sub_vec.size() == 0)break;
				vec.push_back(sub_vec);
				sub_vec.clear();
				q.push(NULL);
				continue;
			}
			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL) q.push(cur->right);
			sub_vec.push_back(cur->val);
		}
		return vec;
	}
};
