/**
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Every iteration: change the direction of the pointer. 
e.g
1->2 curr will point to head, then move head and curr up by 1 position.
 */
class ReverseListIter {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) { return NULL; }
		ListNode* c = head->next;
		ListNode* h = head;
		while (c != NULL) {
			ListNode* temp = c->next;
			c->next = h;
			h = c;
			c = temp;
		}
		head->next = NULL;
		return h;
	}

	ListNode* reverseListRecursive(ListNode* head) {
		if (head == NULL) { return NULL; }
		ListNode* ret = helper(head, head->next);
		head->next = NULL;
		return ret;
	}
	
	ListNode* helper(ListNode* n1, ListNode* n2) {
		if (n2 != NULL) {
			ListNode* temp = n2->next;
			n2->next = n1;
			n1 = n2;
			n2 = temp;
			return helper(n1, n2);
		}
		else {
			return n1;
		}
	}
};