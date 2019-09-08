/*

My Solution:
build a hash table with key of id, and value of a pointer that pointed to itself.
Loop through the list 2 times, the first time just build the next pointer.
Next time build the random pointer.
*/


class CopyListWithRandomPtrSolution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) { return NULL; }
		Node* original = head;
		Node* newHead = new Node(original->val, NULL, NULL);
		Node* ret = newHead;
		original = original->next;

		unordered_map<int, Node*> hash;
		hash[ret->val] = ret;
		// Built up the hash table
		while (original != NULL) {
			newHead->next = new Node(original->val, NULL, NULL);
			Node* temp2 = newHead->next;
			hash[newHead->next->val] = temp2;
			original = original->next;
			newHead = newHead->next;
		}

		// connect random pointer based on the hash table
		original = head;
		newHead = ret;
		while (original != NULL) {
			if (original->random == NULL) { newHead->random = NULL; }
			else { newHead->random = hash[original->random->val]; }
			original = original->next;
			newHead = newHead->next;
		}

		return ret;
	}
};