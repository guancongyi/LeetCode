/*

*/

class PopulatingRightPtrsIISolution {
public:
	queue<Node*> Q;

	Node* connect(Node* root) {
		if (root == NULL) { return NULL; }
		Q.push(root);
		Q.push(NULL);
		
		Node* last = root;
		int countNull = 0;
		while (Q.size()) {
			Node* cur = Q.front();
			Q.pop();
			if (cur == NULL && countNull == 1) { break; }
			if (cur == NULL) {
				countNull++;
				Q.push(NULL);
				last = Q.front();
			}
			else{
				countNull = 0;
				if (cur != last) {
					last->next = cur;
					last = cur;
				}
				if (cur->left != NULL) { Q.push(cur->left); }
				if (cur->right != NULL) { Q.push(cur->right); }
			}
		}

		return root;

	}

	

	//void connectII(Node* root, Node* l, Node * r) {
	//	if (root == NULL)return;
	//	if (l == NULL && r == NULL)return;
	//	else {
	//		// left is not empty
	//		if (l != NULL) {
	//			if (r != NULL) { l->next = r; }
	//			else {
	//				l->next = findNext(root);
	//			}
	//		}
	//		// on the other hand 
	//		if (r != NULL) {
	//			r->next = findNext(root);
	//		}

	//	}
	//	if(l!=NULL){ connectII(l, l->left, l->right); }
	//	connectII(l, l->right, r->left);

	//	/*if(l->right == NULL){ connectII(r, NULL, r->left); }
	//	else if(r->left == NULL) {connectII(l, l->right,NULL);}*/

	//	if (r != NULL) {connectII(r, r->left, r->right);}
	//}

	//Node* findNext(Node* cur) {
	//	cur = cur->next;
	//	while (cur != NULL) {
	//		if (cur->left != NULL ) { return cur->left; }
	//		if (cur->right != NULL) { return cur->right; }
	//		else {
	//			cur = cur->next;
	//		}
	//	}
	//	return 0;
	//}

};