

class ConstructBTSolution {
public:

	TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() != inorder.size() || preorder.size() == 0) { return NULL; }
		map<int, int> umIN; // number -- its id starts from 1
		map<int, int> umPRE; // number -- its id starts from 1
		for (size_t j = 0; j < inorder.size(); j++){
			umIN[inorder[j]] = j+1;
			umPRE[preorder[j]] = j + 1;
		}

		TreeNode* head = new TreeNode(preorder[0]);
		TreeNode* trav = head;
		int parent = head->val;
		int first = 0;
		
		for (size_t i = 1; i < preorder.size(); i++){
			int cur = preorder[i];
			int parentID = umIN[parent];
			int curID = umIN[cur];
			TreeNode* temp = new TreeNode(cur);
			if (curID < parentID) { // go to left
				trav->left = temp;
				// two cases: cur is left most / root
				
				if (cur == inorder[first]) {
					// case 2: root
					if (umPRE[cur]-1 == umIN[cur] ) {
						trav = trav->left;
						parent = cur;
						first += 2;
					}
					// case 1: left most
					else {
						parent = cur;
						first += 2;
					}
					
				}	
				
				else {
					trav = trav->left;
					parent = trav->val;
				}
			}
			else { // go to right
				trav->right = temp;
				trav = trav->right;
				parent = cur; 
			}

			if (i == umIN[head->val]-1) { 
				parent = head->val;
				trav = head;
			}

		}

		return head;
	}

	void preorder(TreeNode* n) {
		if (n == NULL) return ;
		cout << n->val << " ";
		preorder(n->left);
		preorder(n->right);
	}

	void inorder(TreeNode* n) {
		if (n == NULL) return;
		preorder(n->left);
		cout << n->val << " ";
		preorder(n->right);
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	}

};