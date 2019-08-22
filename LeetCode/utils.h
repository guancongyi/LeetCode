#ifndef NODE
#define NODE

class Node {
public:
	int val;
	Node* next;
	Node* random;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

#endif // !NODE

#ifndef TREENODE
#define TREENODE

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
#endif TREENODE

#ifndef LISTNODE
#define LISTNODE

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
#endif LISTNODE

