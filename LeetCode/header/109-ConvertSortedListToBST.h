class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> vec;
		while (head != NULL) {
			vec.push_back(head->val);
			head = head->next;
		}
		TreeNode* root = binarySearch(vec, 0, vec.size());
		return root;
	}

	TreeNode* binarySearch(vector<int>& vec, int l, int r) {
		if (l >= r) {
			return NULL;
		}
		cout << vec[(l + r) / 2] << endl;
		TreeNode* root = new TreeNode(vec[(r + l) / 2]);
		root->left = binarySearch(vec, l, (r + l) / 2);
		root->right = binarySearch(vec, ((r + l) / 2) + 1, r);

		return root;

	}
};