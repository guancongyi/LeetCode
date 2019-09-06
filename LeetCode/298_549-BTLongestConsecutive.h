/*
	each node contain left : [inc, dec]
					  right : [inc, dec]
*/


class BTLongestCOnsecutiveSolution {
public:
	int longestConsecutiveI(TreeNode* root) {

		return helper(root, NULL, 0);
	}

	int helper(TreeNode* n, TreeNode* p, int len) {
		if (n == NULL) return len;
		if (p != NULL && n->val == (p->val + 1)) {
			len += 1;
		}
		else {
			len = 1;
		}

		int l = helper(n->left, n, len);
		int r = helper(n->right, n, len);
		return max(len, max(l, r));
	}

	int Max = 0;
	int longestConsecutiveII(TreeNode* root) {
		search(root);
		return Max;

	}

	pair<int,int> search(TreeNode* n) {
		

		if (n == NULL) return { 0,0 };
		int inc = 1, dec = 1;
		auto left = search(n->left);
		auto right = search(n->right);
		if (n->left != NULL) {
			// inc
			if (n->val == n->left->val + 1) {
				inc = left.first + 1;
			}
			else if (n->val == n->left->val - 1) {
				dec = left.second + 1;
			}
		}
		if (n->right != NULL) {
			if (n->val == n->right->val + 1) {
				inc = max(inc, right.first + 1);
			}
			else if (n->val == n->right->val - 1) {
				dec = max(right.second + 1, dec);
			}
		}


		Max = max(Max, inc + dec - 1);
		return { inc, dec };


	}


};