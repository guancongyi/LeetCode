class PopulatingRightPtrsIISolution {
public:
	Node* connect(Node* root) {
		if (root == NULL) { return NULL; }
		// connect children
		//preorder(root);
		connectSubTrees(root);
		return root;

	}
	void connectSubTrees(Node* root) {
		if (root == NULL) return;
		if (root->left != NULL && root->right != NULL) {
			root->left->next = root->right;
		}
		if (root->left != NULL && root->right == NULL) {
			if (root->next != NULL && root->next->left != NULL) root->left->next = root->next->left;
			else if (root->next != NULL && root->next->right != NULL) root->left->next = root->next->right;
		}
		if (root->right != NULL ){
			if (root->next != NULL && root->next->left != NULL) root->right->next = root->next->left;
			else if (root->next != NULL && root->next->right != NULL) root->right->next = root->next->right;
		}
		
		connectSubTrees(root->left);
		connectSubTrees(root->right);

	}

private:


};