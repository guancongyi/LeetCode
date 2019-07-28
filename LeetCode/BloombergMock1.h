class BloomMock1Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		for (int i = 0; i < numRows; i++) {
			vector<int> row(i + 1);
			for (int j = 0; j < i + 1; j++) {
				if (j == 0) { row[j] = 1; }
				else if (j == i) { row[j] = 1; }
				else { row[j] = 0; }
			}
			ret.push_back(row);

		}
		for (int i = 0; i < numRows; i++) {
			if (i != 0 && i + 1 < numRows) {
				vector<int> cur = ret[i];
				vector<int> next = ret[i + 1];
				for (int j = 0; j < cur.size(); j++) {
					if (j + 1 < cur.size()) {
						next[j + 1] = cur[j] + cur[j + 1];
					}
				}
				ret[i + 1] = next;
			}
		}
		return ret;
	}
};


/*
 * Definition for a binary tree node.
 * 
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class WidthOfBTSolution {
public:
	unordered_map<int, int> um;
	int widthOfBinaryTree(TreeNode* root) {
		int level = 1;
		stack<TreeNode*> s;
		s.push(root);
		if (root == NULL) { return 0; }
		else {
			while (!s.empty()) {
				TreeNode* temp = s.top();
				s.pop();
			}
		}

	}
};