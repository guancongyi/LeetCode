

class Add2NumbersSolution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* first = l1;
		ListNode* second = l2;
		ListNode* trav = new ListNode(0);
		ListNode* res = trav;
		int carry = 0, sum;
		while (true) {
			if (first != NULL || second != NULL) {

				if (first != NULL && second != NULL) sum = first->val + second->val + carry;
				else if (first != NULL && second == NULL)sum = first->val + carry;
				else if (first == NULL && second != NULL)sum = second->val + carry;

				if (sum >= 10) { carry = 1; trav->next = new ListNode(sum - 10); }
				else { trav->next = new ListNode(sum); carry = 0; }
				trav = trav->next;

				if (first != NULL)first = first->next;
				if (second != NULL)second = second->next;
			}
			else {
				if (carry == 1)trav->next = new ListNode(1); carry = 0;
				break;
			}
		}

		return res->next;
	}
};