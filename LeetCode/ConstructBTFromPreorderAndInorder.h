

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		unordered_map<int, int> um;
		for (size_t j = 0; j < inorder.size(); j++){um[inorder[j]] = j+1;}

		TreeNode* head = new TreeNode(preorder[0]);
		TreeNode* trav = head;
		int parent = head->val;
		
		for (size_t i = 1; i < preorder.size(); i++){
			int parentID = um[inorder[parent]];
			int curID = um[inorder[preorder[i]]];
			TreeNode* temp = new TreeNode(preorder[i]);
			
			if (curID < parentID) { // go to left
				trav->left = temp;
				if (parentID - curID != 1) {
					trav = trav->left;
					parent = preorder[i];
				}	
			}
			else { // go to right
				trav->right = temp;
				trav = trav->right;
				parent = preorder[i]; 
			}

			if (i == um[inorder[head->val]]) { parent = head->val; }

		}

		return head;
	}




};