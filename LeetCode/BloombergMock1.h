/*BloomMock1*/


class PascalSolution {
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
 * Start with a BT traversal, store every node in 
 * an array.
 * For each level, store the left most node and right most node.
 */
#ifndef TREENODE
#define TREENODE

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif TREENODE


class WidthOfBTSolution {
public:

	int widthOfBinaryTree(TreeNode* root) {
		vector<pair<int, int>> vec({});
		return helper(root,0, 1, vec);
	}

	int helper(TreeNode* cur, unsigned int level, unsigned int id, vector<pair<int, int>>& vec) {
		if (cur == NULL) return 0;
		if (vec.size() == level) vec.push_back({ id, id });
		else { vec[level].second = id; }
		return std::max({ vec[level].second - vec[level].first + 1, helper(cur->left, level + 1, id * 2, vec), helper(cur->right, level + 1, 1 + id * 2, vec) });

	}
};