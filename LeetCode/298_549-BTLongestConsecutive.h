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

	int longestConsecutiveII(TreeNode* root) {
		return search(root, NULL, 0, -1);
	}

	int search(TreeNode* n, TreeNode* p, int oldLen, int big) {
		
		if (n==NULL) return oldLen;
		int len = 0;
		// big means the parent is the biggest 
		if (p!= NULL && big==1 && n->val == p->val + 1) { len += 1; big = 1; }
		else if (p!=NULL && big==0 && n->val == p->val - 1) { len += 1; big = 0; }
		else { 
			if (p!=NULL && n->val == p->val + 1) {
				big = 1; len =2;
			}
			else if (p != NULL && n->val == p->val - 1) {
				big = 0; len =2;
			}
			else {
				big = -1; len = 1;
			}
		}

		int l = search(n->left, n, len, big);
		int r = search(n->right, n, len, big);
		if ( ((n->left != NULL && n->right != NULL) && (n->left->val == n->val - 1) && (n->right->val = n->val + 1)) ||
			((n->left != NULL && n->right != NULL) && (n->left->val == n->val + 1) && (n->right->val = n->val - 1))){
			return max(len, l + r -1);
		}
		return max(len, max(l, r));
	}


};