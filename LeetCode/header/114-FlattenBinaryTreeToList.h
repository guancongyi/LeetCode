/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FlattenBinaryTreeSolution {
public:
	void flatten(TreeNode* root) {

		if (root == NULL) return;
		flatten(root->left);
		flatten(root->right);

		if (root->right != NULL && root->left != NULL) {
			TreeNode* temp = root->left;
			while (temp != NULL) {
				if (temp->right == NULL) break;
				temp = temp->right;
			}
			temp->right = root->right;
			root->right = root->left;
		}
		else if (root->right == NULL) {
			root->right = root->left;
		}
		root->left = NULL;
	}


};
