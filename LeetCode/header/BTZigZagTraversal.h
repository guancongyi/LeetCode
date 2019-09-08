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
		
		deque<TreeNode*> q;
		int level = 0;
		if(root!=NULL)q.push_back(root);

		while (!q.empty()) {
			deque<TreeNode*> temp = q;
			vector<int> row;
			if (level % 2) {
				// r -> l 
				while (!q.empty()) {
					row.push_back(q.back()->val);
					q.pop_back();
				}
			}
			else {
				// l -> r
				while (!q.empty()) {
					row.push_back(q.front()->val);
					q.pop_front();
				}
			}
			if (row.size() != 0)ret.push_back(row); 
			// bfs
			while (!temp.empty()) {
				TreeNode* cur = temp.front();
				temp.pop_front();
				if (cur != NULL) {
					if (cur->left != NULL)q.push_back(cur->left);
					if (cur->right != NULL)q.push_back(cur->right);
				}
			}
			level++;
			
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