class LinkedListCycleSolution {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL) return 0;

		ListNode* slow = head;
		if (head->next != NULL)head = head->next;
		ListNode* fast = head;

		while (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
			if (fast == NULL)return 0;
			fast = fast->next;
			if (fast == NULL)return 0;

			if (slow == fast) return 1;

		}

		return 0;
	}
};