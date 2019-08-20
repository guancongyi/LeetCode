/*
Use BFS
1. first check which level
2. then pop 
3. push its children into q base on its children's level
*/

class BTZigZagSolution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		deque<int> row;
		queue<TreeNode*> q;
		int level = 0;
		
		if (root != NULL) {
			q.push(root);
			ret.push_back({ root->val });
		}

		int count = pow(2, level);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			count--;
			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL)q.push(cur->right);

			// push items in next level to deque
			if (cur->left != NULL) row.push_back(cur->left->val);
			if (cur->right != NULL)row.push_back(cur->right->val);

			if (count == 0 || q.empty()) {
				level++;
				count = pow(2, level);
				vector<int> temp;
				while(!row.empty()) {
					// at odd level, r to l
					if (level % 2) {
						temp.push_back(row.back());
						row.pop_back();
					}
					// at even level, l to r
					else {
						temp.push_back(row.front());
						row.pop_front();
					}
				}
				if(!temp.empty())ret.push_back(temp);
				
			}

			

		}
		return ret;
		
	}

	//vector<vector<int>> helper(TreeNode* cur, int level) {
	//	// at odd number level: left to right
	//	if (level % 2) {

	//	}
	//	// otherwise
	//	else {

	//	}
	//}
};