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

	vector<vector<int>> levelOrderRecursive(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res;
		helper(res, root, 0);
		return res;
	}

	void helper(vector<vector<int>>& res, TreeNode* root, int level) {
		if (root == NULL) return;


		if (level >= res.size()) {
			vector<int> cur;
			cur.push_back(root->val);
			res.push_back(cur);
		}
		else {
			cout << res[level][0];
			res[level].push_back(root->val);
		}
		helper(res, root->left, level + 1);
		helper(res, root->right, level + 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == NULL)return{};
		queue<TreeNode*> q;
		q.push(root);
		int level = 0;
		vector<vector<int>> res;

		while (!q.empty()) {
			level = q.size();
			vector<int> row;

			while (level != 0) {
				TreeNode* cur = q.front();
				q.pop();

				if (cur != NULL) {
					row.push_back(cur->val);
					if (cur->left != NULL)q.push(cur->left);
					if (cur->right != NULL)q.push(cur->right);
				}
				level--;
			}

			res.push_back(row);
		}
		reverse(res.begin(), res.end());
		return res;

	}

	vector<vector<int>> levelOrderBottom2(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res;
		helper2(res, root, 0);
		return res;
	}

	void helper2(vector<vector<int>>& res, TreeNode* root, int level) {
		if (root == NULL) return;


		vector<int> cur;
		if (level >= res.size()) {
			//cur.push_back(root->val);
			res.insert(res.begin(), cur);
		}



		helper2(res, root->left, level + 1);
		helper2(res, root->right, level + 1);
		res[res.size() - level - 1].push_back(root->val);
	}
		
	

};
