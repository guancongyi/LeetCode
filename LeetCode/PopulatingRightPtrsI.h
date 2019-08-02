/*
// Definition for a Node.
My solution:
First:
connect every left and right from the same subtree
Then:
connect every right node to its adjacent left node




*/

class PopulatingRightPtrsSolution {
public:
	Node* connect(Node* root) {
		if (root == NULL) { return NULL; }
		// connect children
		preorder(root);
		connectSubTrees(root->left, root->right);
		return root;

	}
	void connectSubTrees(Node* l, Node* r) {
		if(l == NULL && r == NULL) return;
		l->next = r;
		connectSubTrees(l->left, l->right);
		connectSubTrees(r->left, r->right);
		connectSubTrees(l->right, r->left);

	}

	void preorder(Node* root) {
		if (root == NULL) return ;
		// connect left and right children while traverse down
		if (root->left != NULL) {
			root->left->next = root->right;
		}
		preorder(root->left);
		preorder(root->right);
	}

};